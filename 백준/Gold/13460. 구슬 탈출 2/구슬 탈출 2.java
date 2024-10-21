import java.util.*;

public class Main {

    public static class Info
    {
        public int y;
        public int x;
        public int cnt;
        Info(int yy, int xx, int cc) {
            y = yy;
            x = xx;
            cnt = cc;
        }
    }
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();

        sc.nextLine();
        
        int rY = -1, rX = -1, bY = -1, bX = -1;
        
        char board[][] = new char[N][M];
        
        for(int y = 0; y < N; y++)
        {
            char str[] = sc.nextLine().toCharArray();
            for(int x = 0; x < M; x++)
            {
                board[y][x] = str[x];
                if(board[y][x] == 'R') { rY = y; rX = x; board[y][x] = '.'; }
                else if(board[y][x] == 'B') { bY = y; bX = x; board[y][x] = '.'; }
            }
        }

        Queue<Info> rQu = new LinkedList<>(), bQu = new LinkedList<>();
        rQu.add(new Info(rY, rX, 0)); bQu.add(new Info(bY, bX, 0));
        
        int answer = -1;

        while(!rQu.isEmpty())
        {
            Queue<Info> next_rQu = new LinkedList<>(), next_bQu = new LinkedList<>();

            while(!rQu.isEmpty())
            {
                int curr_rY = rQu.peek().y;
                int curr_rX = rQu.peek().x;
                int curr_rCnt = rQu.peek().cnt + 1;
                int curr_bY = bQu.peek().y;
                int curr_bX = bQu.peek().x;
                int curr_bCnt = bQu.peek().cnt + 1;
                
                rQu.remove(); bQu.remove();
                
                for(int dir = 1; dir <= 4; dir++)
                {
                    char c001 = '-';
                    int nextY001 = -1;
                    int nextX001 = -1;
                    int nextY002 = -1;
                    int nextX002 = -1;

                    switch(dir)
                    {
                        case 1: 
                            if(curr_rY <= curr_bY) {
                                c001 = 'R';
                                nextY001 = curr_rY;
                                nextY002 = curr_bY;
                                nextX001 = curr_rX; 
                                nextX002 = curr_bX;
                            } else {
                                c001 = 'B';
                                nextY001 = curr_bY; 
                                nextY002 = curr_rY;
                                nextX001 = curr_bX;
                                nextX002 = curr_rX;
                            }
                            while(true) {
                                if(board[nextY001-1][nextX001] == 'O') { 
                                    --nextY001;
                                    break;
                                }
                                else if(board[nextY001-1][nextX001] == '.') {
                                    --nextY001;
                                }
                                else break;
                            }
                            while(true) {
                                if(board[nextY002-1][nextX002] == 'O') { 
                                    --nextY002;
                                    break; 
                                } else if(board[nextY002-1][nextX002] == '.') {
                                    if(nextY002-1 == nextY001 && nextX002 == nextX001) break;
                                    else --nextY002;
                                }
                                else break;
                            }
                            break;
                        case 2:
                            if(curr_rY >= curr_bY) {
                                c001 = 'R';
                                nextY001 = curr_rY;
                                nextY002 = curr_bY;
                                nextX001 = curr_rX;
                                nextX002 = curr_bX;
                            } else {
                                c001 = 'B';
                                nextY001 = curr_bY; nextY002 = curr_rY;
                                nextX001 = curr_bX; nextX002 = curr_rX;
                            }
                            while(true) {
                                if(board[nextY001+1][nextX001] == 'O') { 
                                    ++nextY001; 
                                    break;
                                } else if(board[nextY001+1][nextX001] == '.') ++nextY001;
                                else break;
                            }
                            while(true) {
                                if(board[nextY002+1][nextX002] == 'O') { 
                                    ++nextY002;
                                    break; 
                                } else if(board[nextY002+1][nextX002] == '.') {
                                    if(nextY002+1 == nextY001 && nextX002 == nextX001) break;
                                    else ++nextY002;
                                } else break;
                            }
                            break;
                        case 3:
                            if(curr_rX <= curr_bX) {
                                c001 = 'R';
                                nextY001 = curr_rY;
                                nextY002 = curr_bY;
                                nextX001 = curr_rX; 
                                nextX002 = curr_bX;
                            } else {
                                c001 = 'B';
                                nextY001 = curr_bY;
                                nextY002 = curr_rY;
                                nextX001 = curr_bX;
                                nextX002 = curr_rX;
                            }
                            while(true)
                            {
                                if(board[nextY001][nextX001-1] == 'O') { 
                                    --nextX001;
                                    break;
                                } else if(board[nextY001][nextX001-1] == '.') --nextX001;
                                else break;
                            }
                            while(true)
                            {
                                if(board[nextY002][nextX002-1] == 'O') { 
                                    --nextX002;
                                    break; 
                                } else if(board[nextY002][nextX002-1] == '.') {
                                    if(nextX002-1 == nextX001 && nextY002 == nextY001) break;
                                    else --nextX002;
                                }
                                else break;
                            }
                            break;
                        case 4:
                            if(curr_rX >= curr_bX) {
                                c001 = 'R';
                                nextY001 = curr_rY; 
                                nextY002 = curr_bY;
                                nextX001 = curr_rX; 
                                nextX002 = curr_bX;
                            } else {
                                c001 = 'B';
                                nextY001 = curr_bY;
                                nextY002 = curr_rY;
                                nextX001 = curr_bX;
                                nextX002 = curr_rX;
                            }
                            while(true)
                            {
                                if(board[nextY001][nextX001+1] == '.') ++nextX001;
                                else if(board[nextY001][nextX001+1] == 'O') {
                                    ++nextX001; 
                                    break;
                                }
                                else break;
                            }
                            while(true)
                            {
                                if(board[nextY002][nextX002+1] == 'O') {
                                    ++nextX002;
                                    break;
                                } else if(board[nextY002][nextX002+1] == '.') {
                                    if(nextX002+1 == nextX001 && nextY002 == nextY001) break;
                                    else ++nextX002;
                                }
                                else break;
                            }
                            break;
                    }
                    
                    if(c001 == 'R')
                    {
                        if(board[nextY001][nextX001] == 'O' && board[nextY002][nextX002] != 'O') {
                            answer = curr_rCnt;
                            break;
                        } else if(board[nextY002][nextX002] != 'O') {
                            if(nextY001 != curr_rY || nextX001 != curr_rX || nextY002 != curr_bY || nextX002 != curr_bX) {
                                if(curr_rCnt < 10) {
                                    next_rQu.add(new Info(nextY001, nextX001, curr_rCnt));
                                    next_bQu.add(new Info(nextY002, nextX002, curr_bCnt));
                                }
                            }
                        }
                    }
                    else
                    {
                        if(board[nextY002][nextX002] == 'O' && board[nextY001][nextX001] != 'O')
                        { 
                            answer = curr_rCnt;
                            break;
                        } else if(board[nextY001][nextX001] != 'O') {
                            if(nextY002 != curr_rY || nextX002 != curr_rX || nextY001 != curr_bY || nextX001 != curr_bX) {
                                if(curr_rCnt < 10) {
                                    next_rQu.add(new Info(nextY002, nextX002, curr_rCnt));
                                    next_bQu.add(new Info(nextY001, nextX001, curr_bCnt));
                                }
                            }
                        }
                    }
                }
                if(answer != -1) break;
            }
            if(answer != -1) break; 
            else {
                rQu = next_rQu;
                bQu = next_bQu;
            }
        }

        System.out.println("" + answer);
    }
}
