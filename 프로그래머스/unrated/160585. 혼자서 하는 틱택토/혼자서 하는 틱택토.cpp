#include <string>
#include <vector>
#include <cmath>
using namespace std;

// bd[세로][가로]
//   0  1  2
// 0 ㅁ ㅁ ㅁ
// 1 ㅁ ㅁ ㅁ
// 2 ㅁ ㅁ ㅁ
char bd[3][3];

bool BingoCheck()
{
    // 세로
    if(bd[0][0] == bd[1][0] && bd[0][0] == bd[2][0] && bd[0][0] != '.') return true;
    if(bd[0][1] == bd[1][1] && bd[0][1] == bd[2][1] && bd[0][1] != '.') return true;
    if(bd[0][2] == bd[1][2] && bd[0][2] == bd[2][2] && bd[0][2] != '.') return true;
    
    // 가로
    if(bd[0][0] == bd[0][1] && bd[0][0] == bd[0][2] && bd[0][0] != '.') return true;
    if(bd[1][0] == bd[1][1] && bd[1][0] == bd[1][2] && bd[1][0] != '.') return true;
    if(bd[2][0] == bd[2][1] && bd[2][0] == bd[2][2] && bd[2][0] != '.') return true;
    
    // 대각선
    if(bd[0][0] == bd[1][1] && bd[0][0] == bd[2][2] && bd[0][0] != '.') return true;
    if(bd[0][2] == bd[1][1] && bd[0][2] == bd[2][0] && bd[0][2] != '.') return true;
    
    return false;
}

vector<int> o_posY, o_posX, x_posY, x_posX;
vector<bool> is_O_Used, is_X_Used;
int maxCount;
bool is_O_Turn = true;

int answer;

void DFS(int cnt)
{
    if(cnt == maxCount) { answer = 1; return; }
    else
    {
        if(BingoCheck()) return;
        
        if(is_O_Turn)
        {
            for(int i = 0; i < o_posY.size(); i++)
            {
                if(!is_O_Used[i])
                {
                    is_O_Used[i] = true; bd[o_posY[i]][o_posX[i]] = 'O'; is_O_Turn = false;
                    DFS(cnt+1); if(answer == 1) return;
                    is_O_Turn = true; bd[o_posY[i]][o_posX[i]] = '.'; is_O_Used[i] = false;
                }
            }
        }
        else
        {
            for(int i = 0; i < x_posY.size(); i++)
            {
                if(!is_X_Used[i])
                {
                    is_X_Used[i] = true; bd[x_posY[i]][x_posX[i]] = 'X'; is_O_Turn = true;
                    DFS(cnt+1); if(answer == 1) return;
                    is_O_Turn = false; bd[x_posY[i]][x_posX[i]] = '.'; is_X_Used[i] = false;
                }
            } 
        }
    }
}

int solution(vector<string> board) {
    for(int y = 0; y < 3; y++)
        for(int x = 0; x < 3; x++)
        {
            bd[y][x] = '.';
            if(board[y][x] == 'O') { o_posY.push_back(y); o_posX.push_back(x); }
            else if (board[y][x] == 'X') { x_posY.push_back(y); x_posX.push_back(x); }
        }
    
    is_O_Used = vector<bool>(o_posY.size(),0); is_X_Used = vector<bool>(x_posY.size(),0);
    
    int cnt_O = o_posY.size(), cnt_X = x_posY.size(); maxCount = cnt_O + cnt_X;
    if(cnt_O >= cnt_X && abs(cnt_O - cnt_X) < 2) DFS(0);
    
    return answer;
}