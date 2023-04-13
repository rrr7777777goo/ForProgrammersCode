#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> pic;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2, 0);
    
    vector<int> vvvvv(n+2, 0);
    
    for(int i = 0; i < m+2; i++) pic.push_back(vvvvv);
    
    for(int y = 0; y < picture.size(); y++)
        for(int x = 0; x < picture[y].size(); x++)
            pic[y+1][x+1] = picture[y][x];
    
    for(int y = 1; y <= m; y++)
        for(int x = 1; x <= n; x++)
            if(pic[y][x] != 0)
            {
                ++answer[0];
                int color = pic[y][x], cnt = 1;
                pic[y][x] = 0;
                
                queue<int> qY, qX; qY.push(y), qX.push(x);
                
                while(!qY.empty())
                {
                    queue<int> tY, tX;
                    
                    while(!qY.empty())
                    {
                        int currY = qY.front(), currX = qX.front(); qY.pop(); qX.pop();
                        
                        for(int i = 0; i < 4; i++)
                        {
                            int nextY, nextX;
                            switch(i)
                            {
                                case 0: nextY = currY+1; nextX = currX; break;
                                case 1: nextY = currY-1; nextX = currX; break;
                                case 2: nextY = currY; nextX = currX-1; break;
                                case 3: nextY = currY; nextX = currX+1; break;
                            }
                            if(pic[nextY][nextX] == color)
                            {
                                pic[nextY][nextX] = 0; ++cnt;
                                tY.push(nextY); tX.push(nextX);
                            }
                        }
                    }
                    
                    qY = tY; qX = tX;
                }
                if(answer[1] < cnt) answer[1] = cnt;
            }
    
    return answer;
}