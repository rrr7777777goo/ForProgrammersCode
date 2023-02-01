#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    if((s[0] >= 'a' && s[0] <= 'z')) s[0] -= 32;
    
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i-1] == ' ')
        {
           if((s[i] >= 'a' && s[i] <= 'z')) s[i] -= 32;
        }
        else
        {
           if((s[i] >= 'A' && s[i] <= 'Z')) s[i] += 32; 
        }
    }
    
    return s;
}