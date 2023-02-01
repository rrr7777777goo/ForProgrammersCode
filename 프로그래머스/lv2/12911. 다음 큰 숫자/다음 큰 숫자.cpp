#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    
    string s1 = "";
    while(n > 0) { s1 = (char)((n%2) + '0') + s1; n /= 2; }
    
    bool isFind_1 = false, isComplete = false; int cnt_1 = 0;
    for(int i = s1.size() - 1; i >= 0; i--)
    {
        if(s1[i] == '0')
        {
            if(isFind_1)
            {
                s1[i+1] = '0'; s1[i] = '1';
                --cnt_1;
                isComplete = true;
                break;
            }
        }
        else
        {
            isFind_1 = true;
            s1[i] = '0';
            ++cnt_1;
        }
    }
    
    if(!isComplete)
    {
        s1 = '1' + s1;
        --cnt_1;
    }
    
    int idx = s1.size()-1;
    while(cnt_1 > 0)
    {
        s1[idx--] = '1';
        --cnt_1;
    }
    
    int answer = 0; int za = 1;
    for(int i = s1.size() - 1; i >= 0; i--)
    {
        answer += za * (s1[i] - '0');
        za *= 2;
    }
    
    return answer;
}