import java.util.*;
import java.io.*;

public class Main {

    static int R;
    static int C;

    static char[][] board;
    static int answer;

    static boolean[] isAlreadyVisit;

    static void DFS(int y, int x, int val) {
        for(int dir = 1; dir <= 4; dir++) {
            int nY = y;
            int nX = x;
            switch(dir) {
                case 1:
                    --nY;
                    break;
                case 2:
                    ++nY;
                    break;
                case 3:
                    --nX;
                    break;
                case 4:
                    ++nX;
                    break;
            }
            if(nY >= 0 && nY < R && nX >= 0 && nX < C) {
                if(!isAlreadyVisit[board[nY][nX] - 'A']) {
                    isAlreadyVisit[board[nY][nX] - 'A'] = true;
                    DFS(nY, nX, val + 1);
                    isAlreadyVisit[board[nY][nX] - 'A'] = false;
                }
            }
        }

        if(val > answer) answer = val;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stknizer = new StringTokenizer(br.readLine());

        R = Integer.parseInt(stknizer.nextToken());
        C = Integer.parseInt(stknizer.nextToken());

        board = new char[R][C];

        for(int r = 0; r < R; r++) {
            String str = br.readLine();
            for(int c = 0; c < C; c++) {
                board[r][c] = str.charAt(c);
            }
        }

        isAlreadyVisit = new boolean[26];
        isAlreadyVisit[board[0][0] - 'A'] = true;
        DFS(0, 0, 1);

        System.out.println(answer);
    }
}