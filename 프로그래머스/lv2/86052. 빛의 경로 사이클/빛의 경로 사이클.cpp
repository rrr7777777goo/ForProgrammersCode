#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// [세로][가로][앞으로 나아갈 방향]
// 0 : 상 / 2 : 하 / 1 : 좌 / 3 : 우
bool isUsed[500][500][4];

vector<int> solution(vector<string> grid) {
    vector<int> ans;
    
    for(int y = 0; y < grid.size(); y++)
    {
        for(int x = 0; x < grid[y].size(); x++)
        {
            for(int dir = 0; dir < 4; dir++)
            {
                if(isUsed[y][x][dir] == true) continue;
                
                int tY = y, tX = x, tDir = dir, cnt = 0;
                while(!isUsed[tY][tX][tDir])
                {
                     isUsed[tY][tX][tDir] = true; ++cnt;
                     int nextY = tY, nextX = tX, nextDir = tDir;
                    switch(tDir)
                    {
                        case 0:
                            nextY = tY - 1; nextX = tX;
                            if(nextY < 0) nextY = grid.size()-1;
                            break;
                        case 1:
                            nextY = tY; nextX = tX - 1;
                            if(nextX < 0) nextX = grid[0].size()-1;
                            break;
                        case 2:
                            nextY = tY + 1; nextX = tX;
                            if(nextY == grid.size()) nextY = 0;                            
                            break;
                        case 3:
                             nextY = tY; nextX = tX + 1;
                            if(nextX == grid[0].size()) nextX = 0;
                            break;
                    }
                    
                    if(grid[nextY][nextX] == 'L') { ++nextDir; if(nextDir == 4) nextDir = 0; }
                    else if(grid[nextY][nextX] == 'R') { --nextDir; if(nextDir == -1) nextDir = 3; }
                    
                    tY = nextY; tX = nextX; tDir = nextDir;
                } 
                ans.push_back(cnt);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}