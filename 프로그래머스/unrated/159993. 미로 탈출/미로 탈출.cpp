#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> mM(102, vector<char>(102, 'X'));
vector<vector<bool>> resetVisit(102, vector<bool>(102, 0)), isVisited;

int solution(vector<string> maps) {
    isVisited = resetVisit;
    
    queue<int> qu_Y, qu_X;
    
    for(int y = 0; y < maps.size(); y++)
        for(int x = 0; x < maps[0].size(); x++)
        {
            mM[y+1][x+1] = maps[y][x];
            if(maps[y][x] == 'S') { qu_Y.push(y+1); qu_X.push(x+1); isVisited[y+1][x+1] = true; }
        }
    
        
    int valL = 0, valE = 0;
    char findingChar = 'L'; // L : 레버 찾는 중 / E : 출구 찾는 중 / F : 모두 찾음

    while(!qu_Y.empty())
    {
        if(findingChar == 'L') ++valL; else if (findingChar == 'E') ++valE;
        
        queue<int> tqu_Y, tqu_X, rqu;
        
        while(!qu_Y.empty())
        {
            bool isFinish = false;
            int cY = qu_Y.front(), cX = qu_X.front();
            qu_Y.pop(); qu_X.pop();
            
            int nY, nX;
            for(int i = 0; i < 4; i++)
            {
                switch(i)
                {
                    case 0: nY = cY-1; nX = cX; break; // 상
                    case 1: nY = cY+1; break; // 하
                    case 2: nY = cY; nX = cX-1; break; // 좌
                    case 3: nX = cX+1; break; // 우
                }
                
                if(!isVisited[nY][nX])
                {
                    if(mM[nY][nX] == 'O') { isVisited[nY][nX] = true; tqu_Y.push(nY); tqu_X.push(nX); }
                    else if (mM[nY][nX] == 'L')
                    {
                        if(findingChar == 'L')
                        {
                            isVisited = resetVisit;
                            isVisited[nY][nX] = true;
                            tqu_Y = rqu; tqu_X = rqu;
                            tqu_Y.push(nY); tqu_X.push(nX);
                            findingChar = 'E'; isFinish = true;
                            break;
                        }
                    else { isVisited[nY][nX] = true; tqu_Y.push(nY); tqu_X.push(nX); }
                    }
                    else if (mM[nY][nX] == 'E')
                    {
                        if(findingChar == 'E')
                        {
                            findingChar = 'F'; isFinish = true;
                            break;
                        }
                        else { isVisited[nY][nX] = true; tqu_Y.push(nY); tqu_X.push(nX); }
                    }
                    else if (mM[nY][nX] == 'S')
                    {
                        isVisited[nY][nX] = true; tqu_Y.push(nY); tqu_X.push(nX);
                    }
                }   
            } 
            if(isFinish) break;
        }
        
        if(findingChar == 'F') break;
        qu_Y = tqu_Y; qu_X = tqu_X;
    }
    
    if(findingChar == 'F') return valL + valE;
    else return -1;
}