import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long N;

        N = Long.parseLong(br.readLine());

        boolean[] isNotSosu = new boolean[4000001];

        isNotSosu[0] = true;
        isNotSosu[1] = true;

        List<Long> liSosu = new ArrayList<>();

        for (int i = 2; i <= 4000000; i++) {
            if(!isNotSosu[i]) {
                liSosu.add((long) i);
                for(int x = i+i; x <= 4000000; x += i) {
                    isNotSosu[x] = true;
                }
            }
        }

        int answer = 0;

        int leftIdx = 0;
        int rightIdx = 1;

        long sum = liSosu.get(0);

        while(leftIdx < liSosu.size()) {
            if(sum == N) {
                ++answer;
                sum -= liSosu.get(leftIdx++);
                if(rightIdx < liSosu.size()) {
                    sum += liSosu.get(rightIdx++);
                }
            } else if (sum > N) {
                sum -= liSosu.get(leftIdx++);
            } else {
                if(rightIdx < liSosu.size()) {
                    sum += liSosu.get(rightIdx++);
                } else {
                    break;
                }
            }
        }

        System.out.println(answer);
    }
}
