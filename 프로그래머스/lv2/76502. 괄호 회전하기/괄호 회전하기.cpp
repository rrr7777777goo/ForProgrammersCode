#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    
    int len = s.size(), cnt = 0, ans = 0;
    
    while(len > cnt)
    {
        stack<char> sta;
        for(int i = 0; i < len; i++) {
            if(!sta.empty())
            {
                if(sta.top() == '[' && s[i] == ']') sta.pop();
                else if (sta.top() == '{' && s[i] == '}') sta.pop();
                else if (sta.top() == '(' && s[i] == ')') sta.pop();
                else sta.push(s[i]);
            }
            else sta.push(s[i]);
        }
        
        if(sta.empty()) ++ans;
        
        char i = s[0];
        string t = s.substr(1, len-1);
        s = t + i;
        
        ++cnt;
    }
    
    return ans;
}