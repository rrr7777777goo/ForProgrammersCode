#include <string>
#include <vector>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    char buho = '+'; string tmp = "";
    for(int i = 0; i <= my_string.size(); i++)
    {
        if(i == my_string.size())
        {
            if(buho == '+') answer += stoi(tmp);
            else answer -= stoi(tmp);
        }
        else
        {
            if(my_string[i] >= '0' && my_string[i] <= '9') tmp += my_string[i];
            else if(my_string[i] == ' ')
            {
                if(my_string[i-1] == '+' || my_string[i-1] == '-') continue;
            
                if(buho == '+') answer += stoi(tmp);
                else answer -= stoi(tmp);
            
                tmp = "";
            }
            else if(my_string[i] == '+' || my_string[i] == '-') buho = my_string[i];
        }
    }
     
    return answer;
}