#include <string>
#include <vector>
#include <queue>
using namespace std;

bool arr_Route[52][52][52][52];
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    for(int i = 0; i < rectangle.size(); i++)
    {
        int upY = rectangle[i][3], downY = rectangle[i][1], leftX = rectangle[i][0], rightX = rectangle[i][2];
        
        for(int x = leftX; x < rightX; x++)
        {
            bool isWrong = false;
            for(int r = 0; r < rectangle.size(); r++)
            {
                if(r == i) continue;
                int c_uY = rectangle[r][3], c_dY = rectangle[r][1], c_lX = rectangle[r][0], c_rX = rectangle[r][2];
                
                if((c_uY >= upY && upY >= c_dY) && (c_rX >= x && x >= c_lX) && (c_rX >= (x+1) && (x+1) >= c_lX)) { isWrong = true; break; }
            }
            if(!isWrong) { arr_Route[upY][x][upY][x+1] = 1; arr_Route[upY][x+1][upY][x] = 1; }
            
            isWrong = false;
            for(int r = 0; r < rectangle.size(); r++)
            {
                if(r == i) continue;
                int c_uY = rectangle[r][3], c_dY = rectangle[r][1], c_lX = rectangle[r][0], c_rX = rectangle[r][2];
                
                if((c_uY >= downY && downY >= c_dY) && (c_rX >= x && x >= c_lX) && (c_rX >= (x+1) && (x+1) >= c_lX)) { isWrong = true; break; }
            }
            if(!isWrong) { arr_Route[downY][x][downY][x+1] = 1; arr_Route[downY][x+1][downY][x] = 1; }
        }
        
        for(int y = downY; y < upY; y++)
        {
            bool isWrong = false;
            for(int r = 0; r < rectangle.size(); r++)
            {
                if(r == i) continue;
                int c_uY = rectangle[r][3], c_dY = rectangle[r][1], c_lX = rectangle[r][0], c_rX = rectangle[r][2];
                
                if((c_rX >= leftX && leftX >= c_lX) && (c_uY >= y && y >= c_dY) && (c_uY >= (y+1) && (y+1) >= c_dY)) { isWrong = true; break; }
            }
            if(!isWrong) { arr_Route[y][leftX][y+1][leftX] = 1; arr_Route[y+1][leftX][y][leftX] = 1; }
            
            isWrong = false;
            for(int r = 0; r < rectangle.size(); r++)
            {
                if(r == i) continue;
                int c_uY = rectangle[r][3], c_dY = rectangle[r][1], c_lX = rectangle[r][0], c_rX = rectangle[r][2];
                
                if((c_rX >= rightX && rightX >= c_lX) && (c_uY >= y && y >= c_dY) && (c_uY >= (y+1) && (y+1) >= c_dY)) { isWrong = true; break; }
            }
            if(!isWrong) { arr_Route[y][rightX][y+1][rightX] = 1; arr_Route[y+1][rightX][y][rightX] = 1; }
        }
    }
    
    int answer = 0;
    
    queue<int> nextY, nextX;
    
    nextY.push(characterY); nextX.push(characterX);
    
    bool isFind = false;
    while(!isFind)
    {
        ++answer;
        queue<int> tempY, tempX;
        
        while(!nextY.empty())
        {
            int y = nextY.front(); nextY.pop(); int x = nextX.front(); nextX.pop();
            
            if(arr_Route[y][x][y+1][x])
            {
                if((y+1) == itemY && x == itemX) { isFind = true; break; }
                arr_Route[y][x][y+1][x] = false;
                arr_Route[y+1][x][y][x] = false;
                tempY.push(y+1); tempX.push(x);
            }
            if(arr_Route[y][x][y-1][x])
            {
                if((y-1) == itemY && x == itemX) { isFind = true; break; }
                arr_Route[y][x][y-1][x] = false;
                arr_Route[y-1][x][y][x] = false;
                tempY.push(y-1); tempX.push(x);
            }
            if(arr_Route[y][x][y][x-1])
            {
                if(y == itemY && (x-1) == itemX) { isFind = true; break; }
                arr_Route[y][x][y][x-1] = false;
                arr_Route[y][x-1][y][x] = false;
                tempY.push(y); tempX.push(x-1);
            }
            if(arr_Route[y][x][y][x+1])
            {
                if(y == itemY && (x+1) == itemX) { isFind = true; break; }
                arr_Route[y][x][y][x+1] = false;
                arr_Route[y][x+1][y][x] = false;
                tempY.push(y); tempX.push(x+1);
            }
        }
        
        nextY = tempY; nextX = tempX;
    }
    
    return answer;
}