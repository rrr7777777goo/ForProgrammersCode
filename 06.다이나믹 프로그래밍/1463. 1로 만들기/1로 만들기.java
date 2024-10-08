import java.io.*;

public class Main {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] dp = new int[1000001];

        for(int n = 2; n <= N; n++) {
            int a = dp[n-1];
            int b = -1;
            int c = -1;

            if (n % 2 == 0) { b = dp[n / 2]; if (a > b) { a = b; } }
            if (n % 3 == 0) { c = dp[n / 3]; if (a > c) { a = c; } }

            dp[n] = a + 1;
        }

        System.out.println(dp[N]);
    }
}
