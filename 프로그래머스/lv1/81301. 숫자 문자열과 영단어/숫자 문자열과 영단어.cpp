#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    string tmp;
    
    for(int i = 0; i < s.size(); )
    {
        if(s[i] >= '0' && s[i] <= '9') { tmp += s[i]; i += 1; }
        else if (s[i] == 'z') { tmp += '0'; i += 4; }
        else if (s[i] == 'o') { tmp += '1'; i += 3; }
        else if (s[i] == 't')
        {
            if(s[i+1] == 'w') { tmp += '2'; i += 3; }
            else if (s[i+1] == 'h') { tmp += '3'; i += 5; }
        }
        else if (s[i] == 'f')
        {
            if(s[i+1] == 'o') { tmp += '4'; i += 4; }
            else if (s[i+1] == 'i') { tmp += '5'; i += 4; }
        }
        else if (s[i] == 's')
        {
            if(s[i+1] == 'i') { tmp += '6'; i += 3; }
            else if (s[i+1] == 'e') { tmp += '7'; i += 5; }            
        }
        else if (s[i] == 'e') { tmp += '8'; i += 5; }
        else if (s[i] == 'n') { tmp += '9'; i += 4; }
    }
    
    return stoi(tmp);
}