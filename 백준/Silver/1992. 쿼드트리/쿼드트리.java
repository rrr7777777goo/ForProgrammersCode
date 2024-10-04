import java.util.*;
import java.io.*;

class Data {
	int up;
	int middleUD;
	int down;
	int left;
	int middleLR;
	int right;
	char myColor;
	Data(int u, int dow, int le, int ri, char co) {
		up = u;
		down = dow;
		middleUD = (up + down) / 2;
		left = le;
		right = ri;
		middleLR = (left + right) / 2;
		
		myColor = co;
	}
}

public class Main {
	
	static StringBuilder sb = new StringBuilder("");
	static char[][] movie;
			
	public static void DFS(Data da) {
		boolean isAllSameColor = true;
		
		for(int y = da.up; y < da.down; y++) {
			for(int x = da.left; x < da.right; x++) {
				if(da.myColor != movie[y][x]) {
					isAllSameColor = false;
					break;
				}
			}
			if(!isAllSameColor) {
				break;
			}
		}
		
		if(isAllSameColor) {
			sb.append(da.myColor);
		} else {
			sb.append('(');
			DFS(new Data(da.up, da.middleUD, da.left, da.middleLR, movie[da.up][da.left]));
			DFS(new Data(da.up, da.middleUD, da.middleLR, da.right, movie[da.up][da.middleLR]));
			DFS(new Data(da.middleUD, da.down, da.left, da.middleLR, movie[da.middleUD][da.left]));
			DFS(new Data(da.middleUD, da.down, da.middleLR, da.right, movie[da.middleUD][da.middleLR]));
			sb.append(')');
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		movie = new char[N][N];
		
		for(int y = 0; y < N; y++) {
			String str = br.readLine();
			for(int x = 0; x < N; x++) {
				movie[y][x] = str.charAt(x);
			}
		}
		
		DFS(new Data(0, N, 0, N, movie[0][0]));

		System.out.println(sb);
	}
}