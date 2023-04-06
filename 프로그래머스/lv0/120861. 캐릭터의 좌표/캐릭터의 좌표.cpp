#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    
    int minX = -1 * (board[0] / 2), maxX = (board[0] / 2),
    minY = -1 * (board[1] / 2), maxY = (board[1] / 2);
    
    for(int i = 0; i < keyinput.size(); i++)
    {
        int nextX = answer[0], nextY = answer[1];
        
        if(keyinput[i].compare("left") == 0) --nextX;
        else if(keyinput[i].compare("right") == 0) ++nextX;
        else if(keyinput[i].compare("up") == 0) ++nextY;
        else if(keyinput[i].compare("down") == 0) --nextY;
        
        if(nextX >= minX && nextY >= minY && nextX <= maxX && nextY <= maxY)
        {
            answer[0] = nextX; answer[1] = nextY;
        }
    }
    
    return answer;
}