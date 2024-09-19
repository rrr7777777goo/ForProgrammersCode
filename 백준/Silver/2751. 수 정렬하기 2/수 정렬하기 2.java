import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        List<Integer> li = new ArrayList<>();

        int cnt = 0;
        while (cnt < N) {
            li.add(Integer.parseInt(br.readLine()));
            ++cnt;
        }
        
        Collections.sort(li);
        
        for (int i = 0; i < N; i++) {
            System.out.println(li.get(i));
        }
    }
}
