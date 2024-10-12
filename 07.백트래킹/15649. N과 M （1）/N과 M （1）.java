import java.util.*;

public class Main {
	
	public static int N;
	public static int M;
	public static int[] arr;
	public static boolean[] isAlreadyUse;
	
	public static void MakeArray(int cnt) {
		
		if(cnt == M) {
			for(int i = 0; i < M; i++) {
				System.out.print("" + arr[i] + " ");
			}
			System.out.println();
			return;
		} else {
			for(int i = 1; i <= N; i++) {
				if(isAlreadyUse[i]) continue;
				arr[cnt] = i;
				isAlreadyUse[i] = true;
				MakeArray(cnt+1);
				isAlreadyUse[i] = false;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // scanner 객체 생성
		N = sc.nextInt();
		M = sc.nextInt();
		
		arr = new int[M];
		isAlreadyUse = new boolean[N+1];
		
		MakeArray(0);
		
	}
}
