import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException{
		// BufferedReader 객체 생성
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// StringTokenizer 객체 생성
		StringTokenizer stknizer = new StringTokenizer(br.readLine());
		
		// 순서대로 값을 입력받는다.
		int N = Integer.parseInt(stknizer.nextToken()); // 초밥 접시 개수
		int d = Integer.parseInt(stknizer.nextToken()); // 초밥의 가짓수
		int k = Integer.parseInt(stknizer.nextToken()); // 연속해서 먹는 접시의 개수
		int c = Integer.parseInt(stknizer.nextToken()); // 쿠폰으로 먹을 수 있는 초밥 종류
		
		// k개를 연속해서 골랐을 때 나오는 최대 초밥 가짓수 (출력해야 하는 값)
		int answer = 0;
		// 투포인터 방식으로 탐색하면서 중간중간 구하게 되는 초밥 가짓수
		int temp = 0;
		
		// k개를 연속해서 골랐을 때 각 초밥의 개수
		int[] cnt = new int[d+1];
		// 현재 나열되어 있는 초밥의 종류
		int[] cb = new int[N];

		// 초밥의 종류를 순서대로 입력받는다.
		for(int n = 0; n < N; n++) {
			cb[n] = Integer.parseInt(br.readLine());
		}
		
		// 쿠폰으로 먹을 수 있는 초밥은 cb에 없어도 먹을 수 있으니 temp값과 cnt[c]값을 1로 설정해준다.
		temp = 1;
		cnt[c] = 1;
		
		// 맨 처음 k개를 연속으로 골랐을 때 초밥의 종류별 개수와 총 가짓수를 구한다.
		int left = 0;
		int right = k-1;
		for(int n = left; n <= right; n++) {
			if(cnt[cb[n]] == 0) ++temp;
			++cnt[cb[n]];
		}
		
		// right를 아래와 같이 증가시켜준다.
		right = (right + 1) % N;
		
		// answer값을 temp로 갱신해준다.
		answer = temp;
		
		// 아래와 같은 방식으로 while문을 작동하면 answer값을 무사히 구할 수 있다.
		while(right != k-1) {
			if(cnt[cb[right]] == 0) ++temp;
			++cnt[cb[right]];
			--cnt[cb[left]];
			if(cnt[cb[left]] == 0) --temp;
			
			left = (left + 1) % N;
			right = (right + 1) % N;

			if(answer < temp) {
				answer = temp;
			}
		}
		
		// 답을 출력해준다.
		System.out.println(answer);
	}
}
