import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        Stack<Integer> stak = new Stack<>();
        int answer = 0;
        
        for(int i = 0; i < moves.length; i++) {
            int x = moves[i]-1;
            
            for(int y = 0; y < board.length; y++) {
                if(board[y][x] == 0) continue;
                
                if(stak.isEmpty()) {
                    stak.push(board[y][x]);
                } else {
                    if(stak.peek() == board[y][x]) {
                        stak.pop();
                        answer += 2;
                    } else {
                        stak.add(board[y][x]);
                    }
                }
                
                board[y][x] = 0;
                break;
            }
            
        }
        
        
        
        return answer;
    }
}