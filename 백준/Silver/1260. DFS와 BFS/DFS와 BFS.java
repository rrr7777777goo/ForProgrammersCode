import java.util.*;
import java.io.*;

public class Main {

    static List<List<Integer>> graph;
    static boolean[] isAlreadyVisit;

    static StringBuffer returnDFS;
    static StringBuffer returnBFS;

    static void DFS(int node) {
        isAlreadyVisit[node] = true;
        returnDFS.append(node);
        returnDFS.append(' ');

        for(int n = 0; n < graph.get(node).size(); n++) {
            if(isAlreadyVisit[graph.get(node).get(n)]) continue;
            DFS(graph.get(node).get(n));
        }
    }

    static void BFS(int firstNode) {
        Queue<Integer> qu = new LinkedList<>();

        isAlreadyVisit[firstNode] = true;
        qu.add(firstNode);
        returnBFS.append(firstNode);
        returnBFS.append(' ');

        while(!qu.isEmpty()) {
            int currentNode = qu.poll();

            for(int n = 0; n < graph.get(currentNode).size(); n++) {
                if(isAlreadyVisit[graph.get(currentNode).get(n)]) continue;

                isAlreadyVisit[graph.get(currentNode).get(n)] = true;
                qu.add(graph.get(currentNode).get(n));
                returnBFS.append(graph.get(currentNode).get(n));
                returnBFS.append(' ');
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int V = Integer.parseInt(stringTokenizer.nextToken());

        graph = new ArrayList<>();

        for(int n = 0; n <= N; n++) {
            graph.add(new ArrayList<>());
        }

        for(int m = 0; m < M; m++) {
            stringTokenizer = new StringTokenizer(br.readLine());
            int node01 = Integer.parseInt(stringTokenizer.nextToken());
            int node02 = Integer.parseInt(stringTokenizer.nextToken());
            graph.get(node01).add(node02);
            graph.get(node02).add(node01);
        }

        for(int n = 1; n <= N; n++) {
            Collections.sort(graph.get(n));
        }

        isAlreadyVisit = new boolean[N+1];
        returnDFS = new StringBuffer("");
        DFS(V);

        isAlreadyVisit = new boolean[N+1];
        returnBFS = new StringBuffer("");
        BFS(V);

        System.out.println(returnDFS);
        System.out.println(returnBFS);
    }
}