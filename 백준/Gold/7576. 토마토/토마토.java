import java.util.*;
import java.io.*;


public class Main {

    static int[][] tomato;

    static class Pos
    {
        int x, y;
        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    };

    public static void main(String[] args) throws IOException {
        tomato = new int[1002][1002];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int N = Integer.parseInt(stringTokenizer.nextToken());

        int totalTomato = M * N;
        int countRipeTomato = 0;

        Queue<Pos> qu = new LinkedList<>();

        for (int y = 1; y <= N; y++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            for (int x = 1; x <= M; x++) {
                tomato[x][y] = Integer.parseInt(stringTokenizer.nextToken());
                if (tomato[x][y] == -1) {
                    --totalTomato;
                } else if (tomato[x][y] == 1) {
                    ++countRipeTomato;
                    qu.add(new Pos(x, y));
                }
            }
        }

        int dayCount = 0;
        
        while (!qu.isEmpty() && countRipeTomato < totalTomato) {
            Queue<Pos> nextQu = new LinkedList<>();

            while (!qu.isEmpty()) {
                Pos currentPos = qu.poll();
                int x = currentPos.x;
                int y = currentPos.y;

                // 위쪽으로 이동
                if (y > 1 && (tomato[x][y - 1] == 0)) {
                    nextQu.add(new Pos(x, y - 1));
                    tomato[x][y - 1] = 1;
                    ++countRipeTomato;
                }

                // 아래쪽으로 이동
                if (y < N && (tomato[x][y + 1] == 0)) {
                    nextQu.add(new Pos(x, y + 1));
                    tomato[x][y + 1] = 1;
                    ++countRipeTomato;
                }

                // 왼쪽으로 이동
                if (x > 1 && (tomato[x - 1][y] == 0)) {
                    nextQu.add(new Pos(x-1,y));
                    tomato[x - 1][y] = 1;
                    ++countRipeTomato;
                }

                // 오른쪽으로 이동
                if (x < M && (tomato[x + 1][y] == 0)) {
                    nextQu.add(new Pos(x + 1, y));
                    tomato[x + 1][y] = 1;
                    ++countRipeTomato;
                }
            }

            if (nextQu.size() > 0) dayCount++;
            qu = nextQu;
        }

        if (countRipeTomato == totalTomato) {
            System.out.println(dayCount); 
        } else {
            System.out.println("-1");
        }

    }
}