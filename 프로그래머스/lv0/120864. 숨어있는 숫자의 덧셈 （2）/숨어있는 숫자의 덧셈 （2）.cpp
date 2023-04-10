#include <string>
#include <vector>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    string str = "";
    for(int i = 0; i <= my_string.size(); i++)
    {
        if(i == my_string.size())
        {
            if(str.compare("") != 0) answer += stoi(str);
            break;
        }
        
        if(my_string[i] >= '0' && my_string[i] <= '9') str += my_string[i];
        else
        {
            if(str.compare("") != 0) { answer += stoi(str); str = ""; }
        }
    }
    
    return answer;
}