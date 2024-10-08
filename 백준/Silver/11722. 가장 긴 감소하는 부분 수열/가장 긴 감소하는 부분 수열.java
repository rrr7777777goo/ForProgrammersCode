import java.io.*;
import java.util.*;

public class Main {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N];
        int[] maxLength = new int[N];

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        for (int i = arr.length - 1; i >= 0; i--) {
            arr[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        maxLength[0] = 1;

        int answer = 1;

        for (int i = 1; i < arr.length; i++) {
            int tempLength = 1;

            for (int x = i - 1; x >= 0; x--) {
                if (arr[x] < arr[i]) {
                    if (tempLength < maxLength[x] + 1) {
                        tempLength = maxLength[x] + 1;
                    }
                }
            }

            maxLength[i] = tempLength;
            if (tempLength > answer) answer = tempLength;
        }

        System.out.println(answer);
    }
}
