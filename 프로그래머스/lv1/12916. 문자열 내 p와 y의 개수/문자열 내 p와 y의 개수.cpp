#include <string>
#include <iostream>
using namespace std;

int cnt_P, cnt_Y;
bool solution(string s)
{
    for(int a = 0; a < s.size(); a++)
    {
        if(s[a] == 'p' || s[a] == 'P') ++cnt_P;
        else if(s[a] == 'y' || s[a] == 'Y') ++cnt_Y;
    }
    
    if(cnt_P == cnt_Y) return true;
    else               return false;
}