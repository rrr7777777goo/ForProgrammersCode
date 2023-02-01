#include <string>
#include <vector>
#include <queue>
using namespace std;

// A : 1 / Z : 26 / 빈칸 : 0
// [세로 : m][가로 : n], Pan에서 사용하는 인덱스 : [1 ~ m][1 ~ n]
int sero, garo;
int pan[31][31];
bool isAlreadyIn[31][31];

struct Block
{
    int x, y; Block(int y, int x) { this->y =y; this->x = x; }
    
    bool operator<(const Block &b) const
    {
        if(b.y == y) return x > b.x;
        else return y > b.y;
    }
};

int solution(int m, int n, vector<string> board) {
    sero = m; garo = n;
    
    for(int y = 0; y < board.size(); y++)
        for(int x = 0; x < board[y].size(); x++)
            pan[y+1][x+1] = board[y][x] - 'A' + 1;
    
    queue<Block> qu_B;
    int answer = 0;
    
    while(true)
    {
        for(int y = 1; y <= sero-1; y++)
        {
            for(int x = 1; x <= garo-1; x++)
            {
                if(pan[y][x] == pan[y][x+1] && pan[y][x+1] == pan[y+1][x+1] && pan[y+1][x+1] == pan[y+1][x])
                {
                    if(pan[y][x] == 0) continue;
                    
                    if(!isAlreadyIn[y][x]) { qu_B.push(Block(y,x)); isAlreadyIn[y][x] = true; ++answer; }
                    if(!isAlreadyIn[y][x+1]) { qu_B.push(Block(y,x+1)); isAlreadyIn[y][x+1] = true; ++answer; }
                    if(!isAlreadyIn[y+1][x+1]) { qu_B.push(Block(y+1,x+1)); isAlreadyIn[y+1][x+1] = true; ++answer; }
                    if(!isAlreadyIn[y+1][x]) { qu_B.push(Block(y+1,x)); isAlreadyIn[y+1][x] = true; ++answer; }
                }
            }
        }
        
        if(qu_B.empty()) break;
        
        while(!qu_B.empty())
        {
            int y = qu_B.front().y, x = qu_B.front().x; qu_B.pop(); 
            pan[y][x] = 0; isAlreadyIn[y][x] = false;
        }        
        
        for(int x = 1; x <= garo; x++)
        {
            int len_0 = 0;
            for(int y = sero; y >= 1; )
            {
                if(pan[y][x] == 0) { ++len_0; y--; }
                else if(len_0 > 0)
                {
                    int y2 = y;
                    for( ; y2 >= 1; y2--)
                    {
                        if(pan[y2][x] == 0) break;
                        pan[y2+len_0][x] = pan[y2][x];
                        pan[y2][x] = 0;
                    }
                    y = y2;
                }
                else y--;
            }
        }   
    }

    return answer;
}