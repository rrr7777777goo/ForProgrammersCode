import java.io.*;
import java.util.*;

public class Main {

    static int[] parent;

    public static class StartEndGajoonchi implements Comparable<StartEndGajoonchi> {
        int start, end, gajoonchi;

        StartEndGajoonchi(int s, int e, int g)
        {
            start = s; end = e; gajoonchi = g;
        }

        @Override
        public int compareTo(StartEndGajoonchi o) {
            if (gajoonchi == o.gajoonchi) {
                if (start == o.start)
                {
                    return start < o.start ? -1 : 1;
                }
                else return end < o.end ? -1 : 1;
            }
            else return gajoonchi < o.gajoonchi ? -1 : 1;
        }
    };

    public static int isFind(int x)
    {
        if (parent[x] == x) return x;
        else return parent[x] = isFind(parent[x]);
    }

    public static void main (String[] args) throws IOException {
        parent = new int [10001];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(stringTokenizer.nextToken());
        int E = Integer.parseInt(stringTokenizer.nextToken());

        PriorityQueue<StartEndGajoonchi> pq = new PriorityQueue<>();

        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < E; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(stringTokenizer.nextToken());
            int b = Integer.parseInt(stringTokenizer.nextToken());
            int c = Integer.parseInt(stringTokenizer.nextToken());

            pq.add(new StartEndGajoonchi(a,b,c));
        }

        int sum = 0;

        int count_sum = V - 1;

        while (count_sum != 0 && !pq.isEmpty())
        {
            StartEndGajoonchi tmp = pq.poll();
            
            int parent_s = isFind(tmp.start);
            int parent_e = isFind(tmp.end);

            if (parent_s != parent_e)
            {
                parent[parent_e] = parent_s;
                sum += tmp.gajoonchi;
                count_sum--;
            }
        }

        if (count_sum == 0) {
            System.out.println(sum);
        } else {
            System.out.println(count_sum);
            System.out.println(0);
        }
    }
}
