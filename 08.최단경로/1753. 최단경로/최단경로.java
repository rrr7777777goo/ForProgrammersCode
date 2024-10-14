import java.io.*;
import java.util.*;

public class Main {


    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(stringTokenizer.nextToken()); // 정점
        int E = Integer.parseInt(stringTokenizer.nextToken()); // 간선

        int K = Integer.parseInt(br.readLine()); // 시작 정점

        Map<Integer, Map<Integer, Integer>> ma = new HashMap<>();

        for (int i = 1; i <= V; i++) {
            ma.put(i, new HashMap<>());
        }

        for (int e = 1; e <= E; e++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int startPoint = Integer.parseInt(stringTokenizer.nextToken());
            int endPoint = Integer.parseInt(stringTokenizer.nextToken());
            int price = Integer.parseInt(stringTokenizer.nextToken());

            Map<Integer, Integer> mMa = ma.get(startPoint);

            if (mMa.containsKey(endPoint)) {
                if(mMa.get(endPoint) > price) {
                    mMa.put(endPoint, price);
                }
            } else {
                mMa.put(endPoint, price);
            }
        }

        boolean[] isVisit = new boolean[V+1];
        int[] valueArr = new int[V+1];
        for (int i = 1; i <= V; i++) {
            valueArr[i] = -1;
        }

        valueArr[K] = 0;

        while(true) {
            int next = -1;
            for (int i = 1; i <= V; i++) {
                if(isVisit[i]) continue;
                if(valueArr[i] == -1) continue;

                if(next == -1 || valueArr[next] > valueArr[i]) next = i;
            }
            if(next == -1) break;
            isVisit[next] = true;

            for (int key : ma.get(next).keySet()) {
                int price = valueArr[next] + ma.get(next).get(key);
                if(valueArr[key] == -1 || valueArr[key] > price) {
                    valueArr[key] = price;
                }
            }
        }

        StringBuilder sb = new StringBuilder("");

        for (int i = 1; i <= V; i++) {
            if (valueArr[i] == -1) {
                sb.append("INF");
                sb.append('\n');
            } else {
                sb.append(valueArr[i]);
                sb.append('\n');
            }
        }

        System.out.println(sb);
    }
}
