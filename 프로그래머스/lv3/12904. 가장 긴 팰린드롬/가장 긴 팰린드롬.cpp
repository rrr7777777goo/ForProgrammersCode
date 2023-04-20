#include <iostream>
#include <string>
using namespace std;

bool dp[2500][2500];

int solution(string s)
{
    int answer=0;

    for(int ca = 1; ca <= s.size(); ca++)
    {
        if(ca <= 2)
        {
            for(int i = 0; i < s.size() - ca + 1; i++)
            {
                if(s[i] == s[i+ca-1]) { dp[i][i+ca-1] = true; answer = ca; }
            }
        }
        else
        {
            for(int i = 0; i < s.size() - ca + 1; i++)
            {
                if(s[i] == s[i+ca-1])
                {
                    if(dp[i+1][i+ca-2]) { dp[i][i+ca-1] = true; answer = ca; }
                }
            }
        }
    }
    
    return answer;
}
