import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());

        char[][] miro = new char[N][M];

        for (int r = 0; r < N; r++) {
            String str = br.readLine();
            for (int c = 0; c < M; c++) {
                miro[r][c] = str.charAt(c);
            }
        }

        boolean[][] isAlreadyVisit = new boolean[N][M];

        LinkedList<Integer> quY = new LinkedList<>();
        LinkedList<Integer> quX = new LinkedList<>();

        quY.add(0);
        quX.add(0);
        isAlreadyVisit[0][0] = true;

        int answer = 0;

        while (!quY.isEmpty()) {
            LinkedList<Integer> nextquY = new LinkedList<>();
            LinkedList<Integer> nextquX = new LinkedList<>();

            ++answer;

            boolean isFind = false;

            while (!quY.isEmpty()) {
                int cY = quY.poll();
                int cX = quX.poll();

                for (int dir = 1; dir <= 4; dir++) {
                    int nY = cY;
                    int nX = cX;
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

                    if (nY >= 0 && nY < N && nX >= 0 && nX < M) {
                        if (nY == N-1 && nX == M-1) {
                            ++answer;
                            isFind = true;
                            break;
                        } else if (miro[nY][nX] == '1' && !isAlreadyVisit[nY][nX]) {
                            isAlreadyVisit[nY][nX] = true;
                            nextquY.add(nY);
                            nextquX.add(nX);
                        }
                    }
                }

                if (isFind) break;
            }
            if (isFind) break;
            quY = nextquY;
            quX = nextquX;
        }

        System.out.println(answer);
    }
}