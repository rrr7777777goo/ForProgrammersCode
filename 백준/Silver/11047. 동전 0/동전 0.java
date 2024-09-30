import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int K;
    static int[] coin;
    static int answer;

    public static void DFS(int maxIdx, int cnt, int money) {
        if(money == 0) {
            if(answer > cnt) answer = cnt;
            return;
        }

        for(int i = 0; i < maxIdx; i++) {
            if (money < coin[i]) break;

            int mok = money / coin[i];

            DFS(i, cnt + mok, money - mok * coin[i]);
        }
    }

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        N = Integer.parseInt(stringTokenizer.nextToken());
        K = Integer.parseInt(stringTokenizer.nextToken());

        coin = new int[N];
        answer = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            coin[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0; i < N; i++) {
            if (K == 0) break;
            else if (K < coin[i]) continue;
            DFS(N, 0, K);
        }

        System.out.println(answer);

    }
}
