import java.io.*;
import java.util.*;

public class Main {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int N, K;

        int[] arr_Item = new int[100];
        int[] multitab = new int[100];

        N = Integer.parseInt(stringTokenizer.nextToken());
        K = Integer.parseInt(stringTokenizer.nextToken());

        stringTokenizer = new StringTokenizer(br.readLine());

        for (int i = 0; i < K; i++) {
            arr_Item[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        int answer = 0;

        for (int i = 0; i < K; i++) {
            boolean isAlready = false;

            for (int j = 0; j < N; j++) {
                if (multitab[j] == arr_Item[i]) {
                    isAlready = true;
                    break;
                }
            }
            if (isAlready) continue;

            for (int j = 0; j < N; j++) {
                if (multitab[j] == 0) {
                    multitab[j] = arr_Item[i];
                    isAlready = true;
                    break;
                }
            }
            if (isAlready) continue;

            int idx = 0, last_Index = 0;

            for (int j = 0; j < N; j++) {
                int temp_Index = i + 1;

                for (int k = i + 1; k < K; k++) {
                    if (multitab[j] == arr_Item[k]) break;
                    temp_Index++;
                }

                if (temp_Index > last_Index) {
                    idx = j;
                    last_Index = temp_Index;
                }
            }

            answer++;

            multitab[idx] = arr_Item[i];
        }
        System.out.println(answer);
    }
}
