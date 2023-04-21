#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int nN, nUmBeR;
map<int, int> ma;
vector<int> dp[9];

int solution(int N, int number) {
    nN = N; nUmBeR = number;

    ma[nN] = 1; dp[1].push_back(nN);

    int val = nN, zari = 1; 
    for(int i = 2; i <= 5; i++)
    {
        zari *= 10;
        val += nN * zari; 
        ma[val] = i; dp[i].push_back(val);
    }


    for(int i = 2; i <= 8; i++)
    {
        int a = 1, b = i - a;
        while(a <= b)
        {
            for(int y = 0; y < dp[a].size(); y++)
            {
                for(int x = 0; x < dp[b].size(); x++)
                {
                    int c1 = dp[a][y] + dp[b][x], c2 = dp[a][y] - dp[b][x],
                    c3 = dp[a][y] * dp[b][x], c4 = -199999999, c5 = dp[b][x] - dp[a][y], c6 = -199999999;
                    if(dp[b][x] != 0) c4 = dp[a][y] / dp[b][x];
                    if(dp[a][y] != 0) c6 = dp[b][x] / dp[a][y];

                    if(ma[c1] == 0 || ma[c1] > i) { ma[c1] = i; dp[i].push_back(c1); }
                    if(ma[c2] == 0 || ma[c2] > i) { ma[c2] = i; dp[i].push_back(c2); }
                    if(ma[c3] == 0 || ma[c3] > i) { ma[c3] = i; dp[i].push_back(c3); }
                    if(c4 != -199999999) if(ma[c4] == 0 || ma[c4] > i) { ma[c4] = i; dp[i].push_back(c4); }
                    if(ma[c5] == 0 || ma[c5] > i) { ma[c5] = i; dp[i].push_back(c5); }
                    if(c6 != -199999999) if(ma[c6] == 0 || ma[c6] > i) { ma[c6] = i; dp[i].push_back(c6); }
                }
            }
            ++a; --b;
        }
    }

    if(ma[nUmBeR] == 0) return -1;
    else return ma[nUmBeR];
}