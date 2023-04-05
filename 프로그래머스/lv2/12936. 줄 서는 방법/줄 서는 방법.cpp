#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long di[21];

bool isUsed[21];

vector<int> solution(int n, long long k) {
    --k;
    
    long long tmp = 1;
    for(int i = 1; i <= 20; i++)
    {
        tmp *= i;
        di[i] = tmp / i;
    }
    
    vector<int> answer;
    
    int cn = n;
    while(cn > 0)
    {
        long long d = di[cn];
        
        int maxcnt = k / d, cnt = 0;
        
        for(int i = 1; i <= n; i++)
        {
            if(!isUsed[i])
            {
                if(cnt == maxcnt) { isUsed[i] = true; answer.push_back(i); break; }
                else ++cnt;
            }
        }
        
        k %= d;
        --cn;
    }
    
    return answer;
}