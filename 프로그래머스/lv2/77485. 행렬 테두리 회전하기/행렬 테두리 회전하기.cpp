#include <string>
#include <vector>
using namespace std;

int board[102][102];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    int cnt = 1;
    for(int y = 1; y <= rows; y++)
        for(int x = 1; x <= columns; x++)
            board[y][x] = cnt++;
    
    vector<int> answer;
    
    for(int q = 0; q < queries.size(); q++)
    {
        int up = queries[q][0], left = queries[q][1], down = queries[q][2], right = queries[q][3];
        
        int nextY = up, nextX = left, prev = board[up][left], mini = board[up][left];
        
        int mode = 0; // 0 : 오른쪽으로 / 1 : 아래로 / 2 : 왼쪽으로 / 3 : 위로
        
        while(true)
        {
            switch(mode)
            {
                case 0:
                    nextX += 1; if(nextX == right) mode++;
                break;
                case 1:
                    nextY += 1; if(nextY == down) mode++;
                break;
                case 2:
                    nextX -= 1; if(nextX == left) mode++;
                break;
                case 3:
                    nextY -= 1; if(nextY == up) mode++;
                break;
            }
            int tmp = board[nextY][nextX]; if(tmp < mini) mini = tmp;
            board[nextY][nextX] = prev; prev = tmp;
            
            if(nextY == up && nextX == left) break;
        }
        
        answer.push_back(mini);
    }
    
    return answer;
}