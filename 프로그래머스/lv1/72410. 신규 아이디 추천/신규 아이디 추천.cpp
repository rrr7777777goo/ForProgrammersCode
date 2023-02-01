#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    int cnt = 0; bool isPreviousPoint = false;
    for(int i = 0; i < new_id.size(); i++)
    {
        if(cnt == 15) break;
        
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            answer += (new_id[i] + 32);
            isPreviousPoint = false; cnt++;
        }
        else if (new_id[i] >= 'a' && new_id[i] <= 'z')
        {
            answer += new_id[i];
            isPreviousPoint = false; cnt++;
        }
        else if (new_id[i] >= '0' && new_id[i] <= '9')
        {
            answer += new_id[i];
            isPreviousPoint = false; cnt++;
        }
        else if (new_id[i] == '-' || new_id[i] == '_')
        {
            answer += new_id[i];
            isPreviousPoint = false; cnt++;
        }
        else if (new_id[i] == '.')
        {
            if(cnt != 0)
            {
                if(!isPreviousPoint)
                {
                    answer += new_id[i];
                    isPreviousPoint = true; cnt++;
                }
            }
        }
    }
    
    if(answer.size() == 0) answer += 'a';
    else if(answer[answer.size()-1] == '.') answer.pop_back();
    
    while(answer.size() <= 2) answer += answer[answer.size() - 1];

    return answer;
}