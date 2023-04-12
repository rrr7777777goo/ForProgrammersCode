#include <string>
using namespace std;

bool isPass[12][12][12][12];

int solution(string dirs) {
    int answer = 0;
    int y = 6, x = 6;
    
    for(int i = 0; i < dirs.size(); i++)
    {
        int nY = -1, nX = -1; bool isMove = false;
        switch(dirs[i])
        {
            case 'D': nY = y-1; nX = x; if(nY >=1) isMove = true; break;
            case 'L': nY = y; nX = x-1; if(nX >=1) isMove = true; break;
            case 'R': nY = y; nX = x+1; if(nX <=11) isMove = true; break;
            case 'U': nY = y+1; nX = x; if(nY <=11) isMove = true; break;
        }
        
        if(isMove)
        {
            if(!isPass[y][x][nY][nX])
            {
                isPass[y][x][nY][nX] = true; isPass[nY][nX][y][x] = true;
                ++answer; 
            }
            y = nY; x = nX;
        }
    }
    
    return answer;
}