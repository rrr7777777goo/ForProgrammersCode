#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isAlreadyCheck[1000001];

int solution(int x, int y, int n) {
    int answer = -1;
    
    queue<int> qu; qu.push(x);
    
    int cnt = 0;
    while(!qu.empty() && answer == -1)
    {
        queue<int> tqu;
        
        while(!qu.empty())
        {
            int t = qu.front(); qu.pop();
            
            int tT[3]; tT[0] = t + n, tT[1] = t * 2, tT[2] = t * 3;
            
            for(int y = 0; y <= 1; y++)
            {
                for(int x = y+1; x <= 2; x++)
                {
                    if(tT[y] < tT[x])
                    {
                        int tmp = tT[y];
                        tT[y] = tT[x];
                        tT[x] = tmp;
                    }
                }
            }
            
            if(tT[0] > 0 && tT[0] <= y)
            {
                if(tT[0] == y)
                {
                    answer = cnt + 1;
                    break;
                }
                else if(!isAlreadyCheck[tT[0]])
                {
                    isAlreadyCheck[tT[0]] = true;
                    tqu.push(tT[0]);
                }
            }
            if(tT[1] > 0 && tT[1] <= y)
            {
                if(tT[1] == y)
                {
                    answer = cnt + 1;
                    break;
                }
                else if(!isAlreadyCheck[tT[1]])
                {
                    isAlreadyCheck[tT[1]] = true;
                    tqu.push(tT[1]);
                }
            }
            if(tT[2] > 0 && tT[2] <= y)
            {
                if(tT[2] == y)
                {
                    answer = cnt + 1;
                    break;
                }
                else if(!isAlreadyCheck[tT[2]])
                {
                    isAlreadyCheck[tT[2]] = true;
                    tqu.push(tT[2]);
                }
            }
        }
        
        qu = tqu;
        ++cnt;
    }
    
    if(x == y) answer = 0;
    return answer;
}