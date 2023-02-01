#include <iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> stk;

int solution(string s)
{
    stk.push(s[0]);
    
    for(int i = 1; i < s.size(); i++)
    {
        if(stk.empty()) stk.push(s[i]);
        else
        {
            if(stk.top() == s[i]) stk.pop();
            else stk.push(s[i]);
        }
    }
    
    if(stk.empty()) return 1;
    else return 0;
}