#include <string>
#include <vector>
#include <map>
using namespace std;

int human[10];
map<string, bool> isAlreadyUsed;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    
    int idx_h = -1; char lastWord = words[0][0];
    for(int i = 0; i < words.size(); i++)
    {
        idx_h = (idx_h + 1) % n;
        ++human[idx_h];
        
        if(isAlreadyUsed[words[i]] || lastWord != words[i][0])
        {
            answer[0] = idx_h + 1;
            answer[1] = human[idx_h];
            break;
        }
        else 
        {
            isAlreadyUsed[words[i]] = true;
            lastWord = words[i][words[i].size() - 1];
        }
    }
 
    return answer;
}