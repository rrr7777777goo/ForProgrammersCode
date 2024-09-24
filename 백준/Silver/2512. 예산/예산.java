import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M;

        N = Integer.parseInt(br.readLine());

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int[] arr = new int[N];
        int maxValue = -1;
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(stringTokenizer.nextToken());
            if(maxValue < arr[i]) maxValue = arr[i];
        }

        M = Integer.parseInt(br.readLine());

        int left = 0;
        int right = maxValue;
        int mid = -1;

        while(left < right) {
            mid = (left + right) / 2;
            if((left + right) % 2 == 1) ++mid;
            // System.out.println("! " + left + " " + mid + " " + right);
            int sum = 0;

            boolean isWrong = false;
            for(int i = 0; i < N; i++) {
                if(arr[i] <= mid) sum += arr[i];
                else sum += mid;

                if(sum > M) {
                    isWrong = true;
                    break;
                }
            }
            // System.out.println(sum);
            if(isWrong) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        System.out.println(left);
    }
}
