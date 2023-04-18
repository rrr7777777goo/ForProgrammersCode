#include <iostream>
#include <vector>
using namespace std;

int dp[2][100000];
int solution(vector<int> sticker)
{
    int answer =0;

    int idx1 = 0, idx2 = 1;
    
    if(sticker.size() == 1) return sticker[0];
    
    dp[0][0] = sticker[idx1++]; dp[1][0] = sticker[idx2++];
    
    for(int i = 1; i < sticker.size(); i++)
    {
        if(i == sticker.size()-1)
        {
            answer = max(dp[0][i-1], dp[1][i-1]);
            break;
        }
        
        if(i == 1)
        {
            dp[0][1] = max(sticker[idx1], dp[0][0]); dp[1][1] = max(sticker[idx2], dp[1][0]);
        }
        else
        {
            dp[0][i] = max(sticker[idx1] + dp[0][i-2], dp[0][i-1]);
            dp[1][i] = max(sticker[idx2] + dp[1][i-2], dp[1][i-1]);
        }
        
        ++idx1; ++idx2;
    }
    
    return answer;
}