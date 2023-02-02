#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int slen, glen;
int mM[102][102];

vector<int> solution(vector<string> maps) {
    slen = maps.size(); glen = maps[0].size();
    for(int y = 0; y < maps.size(); y++)
    {
        for(int x = 0; x < maps[y].size(); x++)
        {
            if(maps[y][x] != 'X') { mM[y+1][x+1] = maps[y][x] - '0'; }
        }
    }
    
    vector<int> ans;
    for(int y = 1; y <= slen; y++)
    {
        for(int x = 1; x <= glen; x++)
        {
            if(mM[y][x] == 0) continue;
            else
            {
                int tmp = mM[y][x]; mM[y][x] = 0;
                
                queue<int> qu_Y, qu_X; qu_Y.push(y); qu_X.push(x);
                
                while(!qu_Y.empty())
                {
                    queue<int> tqu_Y, tqu_X;
                    while(!qu_Y.empty())
                    {
                        int yY = qu_Y.front(); qu_Y.pop(); int xX = qu_X.front(); qu_X.pop();
                        
                        if(mM[yY-1][xX] != 0)
                        {
                            tqu_Y.push(yY-1); tqu_X.push(xX);
                            tmp += mM[yY-1][xX]; mM[yY-1][xX] = 0;
                        }
                        if(mM[yY+1][xX] != 0)
                        {
                            tqu_Y.push(yY+1); tqu_X.push(xX);
                            tmp += mM[yY+1][xX]; mM[yY+1][xX] = 0;                           
                        }
                        if(mM[yY][xX-1] != 0)
                        {
                            tqu_Y.push(yY); tqu_X.push(xX-1);
                            tmp += mM[yY][xX-1]; mM[yY][xX-1] = 0;
                        }
                        if(mM[yY][xX+1] != 0)
                        {
                            tqu_Y.push(yY); tqu_X.push(xX+1);
                            tmp += mM[yY][xX+1]; mM[yY][xX+1] = 0;                           
                        }
                    }           
                    qu_Y = tqu_Y; qu_X = tqu_X;
                }
                ans.push_back(tmp);
            }
        }
    }
    if(ans.size() == 0) ans.push_back(-1);
    sort(ans.begin(), ans.end());
    return ans;
}