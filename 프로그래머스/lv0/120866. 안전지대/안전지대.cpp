#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = board.size() * board[0].size();
    
    for(int y = 0; y < board.size(); y++)
    {
        for(int x = 0; x < board[0].size(); x++)
        {
            if(board[y][x] == 1)
            {
                --answer;
                
                for(int nextY = y-1; nextY <= y+1; nextY++)
                    for(int nextX = x-1; nextX <= x+1; nextX++)
                        if(nextY >= 0 && nextY < board.size()&& nextX >= 0 && nextX < board[0].size())
                            if(board[nextY][nextX] == 0) { board[nextY][nextX] = 2; --answer; }
            }
        }
    }
    
    return answer;
}