import java.io.*;
import java.util.*;

public class Main {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int[] T = new int[1500002];
        int[] P = new int[1500002];
        int[] dp = new int [1500002];
        
        int N = Integer.parseInt(br.readLine());

        StringTokenizer stringTokenizer;
        for(int i = 1; i <= N; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(stringTokenizer.nextToken());
            P[i] = Integer.parseInt(stringTokenizer.nextToken());
        }
        
        for(int i = N; i >= 1; i--) {
            if (i + T[i] > N + 1) {
                dp[i] = dp[i + 1];
            } else {
                dp[i] = dp[i+1] > P[i]+dp[i+T[i]] ? dp[i+1] : P[i]+dp[i+T[i]];
            }
        }
        
        System.out.println(dp[1]);
    }
}
