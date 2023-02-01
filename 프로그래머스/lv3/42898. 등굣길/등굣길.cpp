#include <string>
#include <vector>
using namespace std;

long long dp[101][101];
bool isPuddle[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    dp[1][1] = 1;
    for(int i = 0; i < puddles.size(); i++) isPuddle[puddles[i][1]][puddles[i][0]] = true;
    
    int answer = 0;
    
    for(int y = 1; y <= n; y++)
    {
        for(int x = 1; x <= m; x++)
        {
            if(isPuddle[y][x] || (y == 1 && x == 1)) continue;
            dp[y][x] = (dp[y][x-1] + dp[y-1][x]) % 1000000007;
        }
    }
    
    return dp[n][m];
}