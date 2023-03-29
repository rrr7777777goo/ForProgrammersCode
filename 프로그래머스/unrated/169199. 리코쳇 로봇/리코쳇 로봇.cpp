#include <string>
#include <vector>
#include <queue>
using namespace std;

// 0 : 못가는 길 / 1 : 갈 수 있는 길 / 2 : 도착지점
int bo[102][102];
bool isAlreadyCheck[102][102];

int solution(vector<string> board) {
    
    int startY = 0, startX = 0;
    
    for(int y = 0; y < board.size(); y++)
    {
        for(int x = 0; x < board[0].size(); x++)
        {
            if(board[y][x] == '.') bo[y+1][x+1] = 1;
            else if (board[y][x] == 'R') { bo[y+1][x+1] = 1; startY = y+1; startX = x+1; }
            else if (board[y][x] == 'G') bo[y+1][x+1] = 2;
        }
    }
    
    int answer = -1;
    
    queue<int> qu_Y, qu_X;
    qu_Y.push(startY); qu_X.push(startX);
    isAlreadyCheck[startY][startX] = true;
    
    int cnt = 0;
    while(!qu_Y.empty())
    {
        bool isFind = false;
        queue<int> tqu_Y, tqu_X;
        
        ++cnt;
        while(!qu_Y.empty())
        {
            int posY = qu_Y.front(), posX = qu_X.front();
            qu_Y.pop(); qu_X.pop();
            
            // 상
            int nextY = posY, nextX = posX;
            while(true) { if(bo[nextY-1][nextX] == 0) break; --nextY; }
            
            if(!isAlreadyCheck[nextY][nextX])
            {
                if(bo[nextY][nextX] == 2) { isFind = true; break; }
                else { isAlreadyCheck[nextY][nextX] = true; tqu_Y.push(nextY); tqu_X.push(nextX); }
            }
            
            // 하
            nextY = posY;
            while(true) { if(bo[nextY+1][nextX] == 0) break; ++nextY; }
            
            if(!isAlreadyCheck[nextY][nextX])
            {
                if(bo[nextY][nextX] == 2) { isFind = true; break; }
                else { isAlreadyCheck[nextY][nextX] = true; tqu_Y.push(nextY); tqu_X.push(nextX); }
            }
            
            // 좌
            nextY = posY;
            while(true) { if(bo[nextY][nextX-1] == 0) break; --nextX; }
            
            if(!isAlreadyCheck[nextY][nextX])
            {
                if(bo[nextY][nextX] == 2) { isFind = true; break; }
                else { isAlreadyCheck[nextY][nextX] = true; tqu_Y.push(nextY); tqu_X.push(nextX); }
            }
            
            // 우
            nextX = posX;
            while(true) { if(bo[nextY][nextX+1] == 0) break; ++nextX; }
            
            if(!isAlreadyCheck[nextY][nextX])
            {
                if(bo[nextY][nextX] == 2) { isFind = true; break; }
                else { isAlreadyCheck[nextY][nextX] = true; tqu_Y.push(nextY); tqu_X.push(nextX); }
            }
        }
        
        if(isFind) { answer = cnt; break; }
        qu_Y = tqu_Y; qu_X = tqu_X;
    }
    
    return answer;
}