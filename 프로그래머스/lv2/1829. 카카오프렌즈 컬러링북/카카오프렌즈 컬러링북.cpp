#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> pic;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2,0);
    
    vector<int> ttt(n+2, 0);
    for(int i = 0; i < m+2; i++) pic.push_back(ttt);
    
    for(int y = 0; y < picture.size(); y++)
        for(int x = 0; x < picture[y].size(); x++)
            pic[y+1][x+1] = picture[y][x];
    
    for(int y = 1; y <= m; y++)
    {
        for(int x = 1; x <= n; x++)
        {
            if(pic[y][x] != 0 && pic[y][x] != -1)
            {
                ++answer[0];
                int color = pic[y][x], cnt = 1; pic[y][x] = -1;
                
                queue<int> qY, qX; qY.push(y); qX.push(x);
                
                while(!qY.empty())
                {
                    queue<int> nY, nX;
                    
                    while(!qY.empty())
                    {
                        int nextY = qY.front(), nextX = qX.front(); qY.pop(); qX.pop();
                        
                        int b = -1, a = -1;
                        for(int z = 0; z < 4; z++)
                        {
                            switch(z)
                           {
                                case 0: b = nextY; a = nextX-1; break;
                                case 1: b = nextY; a = nextX+1; break;
                                case 2: b = nextY-1; a = nextX; break;
                                case 3: b = nextY+1; a = nextX; break;
                            }
                            
                            if(pic[b][a] == color)
                            {
                                pic[b][a] = -1;
                                nY.push(b); nX.push(a);
                                ++cnt;
                            }
                        }
                    }
                    
                    qY = nY; qX = nX;
                }
                
                if(cnt > answer[1]) answer[1] = cnt;
            }
        }
    }
    
    return answer;
}