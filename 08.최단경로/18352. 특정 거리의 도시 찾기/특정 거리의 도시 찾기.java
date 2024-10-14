import java.io.*;
import java.util.*;

public class Main {


    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int K = Integer.parseInt(stringTokenizer.nextToken());
        int X = Integer.parseInt(stringTokenizer.nextToken());

        boolean[] isVisit = new boolean[300001];
        List<List<Integer>> route = new ArrayList<>();

        for (int i = 0; i < 300001; i++) {
            route.add(new ArrayList<>());
        }

        for (int m = 0; m < M; m++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(stringTokenizer.nextToken());
            int end = Integer.parseInt(stringTokenizer.nextToken());

            route.get(start).add(end);
        }

        int cnt = 1;

        isVisit[X] = true;
        List<Integer> li = new ArrayList<>();
        li.add(X);

        while(cnt <= K && !li.isEmpty()) {
            List<Integer> nextLi = new ArrayList<>();

            for (int i = 0; i < li.size(); i++) {
                int current = li.get(i);
                for (int a = 0; a < route.get(current).size(); a++) {
                    int next = route.get(current).get(a);
                    if(isVisit[next]) continue;
                    isVisit[next] = true;
                    nextLi.add(next);
                }
            }

            li = nextLi;
            ++cnt;
        }

        if (li.isEmpty()) li.add(-1);

        Collections.sort(li);
        for (int i = 0; i < li.size(); i++) {
            System.out.println(li.get(i));
        }

    }
}
