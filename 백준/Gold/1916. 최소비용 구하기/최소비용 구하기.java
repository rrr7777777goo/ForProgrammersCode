import java.io.*;
import java.util.*;

public class Main {


    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        boolean[][] isHaveRoute = new boolean[1001][1001];
        int[][] priceArr = new int[1001][1001];

        StringTokenizer stringTokenizer;

        for (int i = 0; i < M; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(stringTokenizer.nextToken());
            int end = Integer.parseInt(stringTokenizer.nextToken());
            int price = Integer.parseInt(stringTokenizer.nextToken());

            if (!isHaveRoute[start][end]) {
                isHaveRoute[start][end] = true;
                priceArr[start][end] = price;
            } else {
                priceArr[start][end] = priceArr[start][end] < price ? priceArr[start][end] : price;
            }
        }

        boolean[] isCheck = new boolean[1001];
        int[] values = new int[1001];

        for (int i = 1; i <= N; i++) {
            values[i] = -1;
        }

        stringTokenizer = new StringTokenizer(br.readLine());
        int startPoint = Integer.parseInt(stringTokenizer.nextToken());
        int endPoint = Integer.parseInt(stringTokenizer.nextToken());

        values[startPoint] = 0;

        while(true) {
            int nextPoint = -1;

            for(int i = 1; i <= N; i++) {
                if(isCheck[i]) continue;
                if(values[i] == -1) continue;

                if(nextPoint == -1 || values[i] < values[nextPoint]) {
                    nextPoint = i;
                }
            }
            if(nextPoint == -1) break;
            isCheck[nextPoint] = true;

            for(int i = 1; i <= N; i++) {
                if(!isHaveRoute[nextPoint][i]) continue;

                int val = values[nextPoint] + priceArr[nextPoint][i];
                if(values[i] == -1 || values[i] > val) values[i] = val;
            }
        }

        System.out.println(values[endPoint]);

    }
}
