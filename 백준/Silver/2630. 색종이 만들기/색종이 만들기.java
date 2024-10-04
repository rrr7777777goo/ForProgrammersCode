import java.util.*;
import java.io.*;

class Data {
	int left;
	int right;
	int up;
	int down;
	int myColor;
	Data(int l, int r, int u, int d) {
		left = l;
		right = r;
		up = u;
		down = d;
	}
}

public class Main {
	public static void main(String[] args) throws IOException {
		// BufferedReader 객체 생성
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// 색종이의 길이를 입력받는다.
		int N = Integer.parseInt(br.readLine());
		
		// 색종이 배열 생성
		int[][] colorPaper = new int[N][N];
		
		StringTokenizer stknizer;
		for(int y = 0; y < N; y++) {
			stknizer = new StringTokenizer(br.readLine());
			for(int x = 0; x < N; x++) {
				colorPaper[y][x] = Integer.parseInt(stknizer.nextToken());
			}
		}
		
		int[] answer = new int[2];
		LinkedList<Data> li = new LinkedList<>();
		li.add(new Data(0, N, 0, N));
		
		while(!li.isEmpty()) {
			Data da = li.poll();
			da.myColor = colorPaper[da.up][da.left];
			boolean isWrong = false;
			for(int y = da.up; y < da.down; y++) {
				for(int x = da.left; x < da.right; x++) {
					if(da.myColor != colorPaper[y][x]) {
						isWrong = true;
						break;
					}
				}
				if(isWrong) break;
			}
			
			if(isWrong) {
				int middleLR = (da.left + da.right) / 2;
				int middleUD = (da.up + da.down) / 2;
				li.add(new Data(da.left, middleLR, da.up, middleUD));
				li.add(new Data(middleLR, da.right, da.up, middleUD));
				li.add(new Data(da.left, middleLR, middleUD, da.down));
				li.add(new Data(middleLR, da.right, middleUD, da.down));
			} else {
				++answer[da.myColor];
			}
		}
		
		System.out.println("" + answer[0] + "\n" + answer[1] + "\n");
	}
}