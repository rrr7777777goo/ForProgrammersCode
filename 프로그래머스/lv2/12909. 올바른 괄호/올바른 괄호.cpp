#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int val = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') ++val;
        else if (s[i] == ')') -- val;
        if(val < 0) return false;
    }
    
    if(val == 0) return true;
    else return false;
}