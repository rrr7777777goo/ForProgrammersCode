#include<vector>
#include <queue>
using namespace std;

vector<vector<int>> mmm;

int solution(vector<vector<int> > maps)
{
    if(maps[0][0] == 0 || maps[maps.size() - 1][maps[0].size() - 1] == 0) return -1;
    
    vector<int> ga(maps[0].size() + 2, 0);
    
    for(int i = 0; i < maps.size()+2; i++) mmm.push_back(ga);
    
    for(int y = 0; y < maps.size(); y++)
    {
        for(int x = 0; x < maps[y].size(); x++)
        {
            mmm[y+1][x+1] = maps[y][x];
        }
    }
    
    bool isFind = false;
    int answer = 1;
    
    queue<int> qY, qX; qY.push(1); qX.push(1); 
    
    while(!qY.empty())
    {
        ++answer;
        queue<int> tY, tX;
        
        while(!qY.empty())
        {
            int y = qY.front(), x = qX.front(); qY.pop(); qX.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nY, nX;
                switch(i)
                {
                case 0: nY = y - 1; nX = x; break;
                case 1: nY = y + 1; nX = x; break;
                case 2: nY = y; nX = x-1; break;
                case 3: nY = y; nX = x+1; break;
                }
                
                if(mmm[nY][nX] == 1)
                {
                    if(nY == maps.size() && nX == maps[0].size())
                    {
                        isFind = true; break;
                    }
                    else
                    {
                        mmm[nY][nX] = 0;
                        tY.push(nY); tX.push(nX);
                    }
                }
            }
            if(isFind) break;
        }
        if(isFind) break;
        qY = tY; qX = tX;
    }
    
    if(isFind) return answer;
    else return -1;
}