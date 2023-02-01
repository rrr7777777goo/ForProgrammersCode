#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> restore_doll;
    
    for(int m = 0; m < moves.size(); m++)
    {
        int lin = moves[m] - 1;
        
        bool isCatch = false;
        
        for(int b = board.size()-1; b >= -1; b--)
        {
            if(b == -1)
            {
                isCatch = true;
                restore_doll.push_back(board[b+1][lin]);
                board[b+1][lin] = 0;
                break;
            }
            
            if(board[b][lin] != 0) continue;
            else
            {
                if(b == board.size()-1) break;
                
                isCatch = true;
                restore_doll.push_back(board[b+1][lin]);
                board[b+1][lin] = 0;
                break;
            }
        }
        
        if(isCatch && restore_doll.size() >= 2)
        {
            if(restore_doll[restore_doll.size()-1] == restore_doll[restore_doll.size()-2])
            {
                restore_doll.pop_back(); restore_doll.pop_back();
                answer += 2;
            }
        }
    }
    
    return answer;
}