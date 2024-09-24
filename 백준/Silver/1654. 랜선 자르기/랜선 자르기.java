import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int K, N;
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        K = Integer.parseInt(stringTokenizer.nextToken());
        N = Integer.parseInt(stringTokenizer.nextToken());

        int[] arr = new int[K];

        int maxi = -1;
        for(int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            if(maxi < arr[i]) maxi = arr[i];
        }

        long left = 1;
        long right = maxi;
        long mid = -1;
        while(left < right) {
            mid = (left + right) / 2;

            if((left + right) % 2 == 1) ++mid;

            int sum = 0;

            for(int i = 0; i < arr.length; i++) {
                long cnt = arr[i] / mid;
                sum += cnt;
                if(sum >= N) break;
            }

            if(sum >= N) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(left);
    }
}
