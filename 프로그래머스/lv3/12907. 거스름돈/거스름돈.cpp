#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];
int solution(int n, vector<int> money) {
    int answer = 0;
    
    sort(money.begin(), money.end());
    
    dp[0] = 1;
    
    for(int i = 0; i < money.size(); i++)
    {
        for(int x = money[i]; x <= n; x++)
        {
            dp[x] = (dp[x] + dp[x - money[i]] % 1000000007) % 1000000007;
        }
    }
    
    return dp[n];
}