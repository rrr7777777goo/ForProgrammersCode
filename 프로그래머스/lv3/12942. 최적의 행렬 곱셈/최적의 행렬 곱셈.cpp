#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[201][201];

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    
    for(int ca = 1; ca < matrix_sizes.size(); ca++)
    {
        for(int i = 0; i < matrix_sizes.size() - ca; i++)
        {
            bool isFirst = true;
            int j = i + ca;
            for(int a = 0; a < ca; a++)
            {
                if(isFirst)
                {
                    dp[i][j] = dp[i][i+a] + dp[i+a+1][j]
                        + (matrix_sizes[i][0] * matrix_sizes[i+a][1] * matrix_sizes[j][1]);
                    isFirst = false;
                }
                else
                {
                    if(dp[i][j] > dp[i][i+a] + dp[i+a+1][j]
                        + (matrix_sizes[i][0] * matrix_sizes[i+a][1] * matrix_sizes[j][1]))
                    {
                        dp[i][j] = dp[i][i+a] + dp[i+a+1][j]
                        + (matrix_sizes[i][0] * matrix_sizes[i+a][1] * matrix_sizes[j][1]);
                    }
                }
            }
            
        }
    }

    return dp[0][matrix_sizes.size() - 1];
}