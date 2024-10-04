import java.util.*;
import java.io.*;

/**
 * @author 조근호
 *
 * 백준 1074. Z
 * https://www.acmicpc.net/problem/1074
 * 분할정복 방식을 이용해서 문제를 해결한다.
 * 메모리 : -kb
 * 시간 : -ms
 */

public class Main {
	public static void main(String[] args) throws IOException {
		// BufferedReader 객체 생성
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// StringTokenizer 객체 생성
		StringTokenizer stknizer = new StringTokenizer(br.readLine());
		// 2차원 배열의 크기, 배열은 2^N의 길이를 가진다.
		int N = Integer.parseInt(stknizer.nextToken());
		// 찾으려는 칸의 행 번호(0~(N-1))
		int r = Integer.parseInt(stknizer.nextToken());
		// 찾으려는 칸의 열 번호(0~(N-1))
		int c = Integer.parseInt(stknizer.nextToken());
		
		// 현재 조사하는 범위의 길이, 초기값은 2^N이다.
		int nowLen = 1;
		for(int i = 0; i < N; i++) {
			nowLen *= 2;
		}

		// 문제에서 구하려는 답을 저장하기 위한 변수(배열의 r행 c열에 있는 값)
		int answer = 0;
		
		// 분할정복방식을 이용해서 문제를 해결한다.
		while(nowLen > 1) {
			// 현재 조사하는 범위의 가로or세로 길이를 2로 나눈 값
			int middleRC = nowLen / 2;
			
			// 현재 범위에서 찾고자하는 칸이 우측 아래에 있을 때
			if(r >= middleRC && c >= middleRC) {
				answer += (nowLen * nowLen / 4) * 3;
				r -= middleRC;
				c -= middleRC;
			} // 현재 범위에서 찾고자하는 칸이 좌측 아래에 있을 때 
			else if(r >= middleRC) {
				answer += (nowLen * nowLen / 4) * 2;
				r -= middleRC;
			} // 현재 범위에서 찾고자하는 칸이 우측 위에 있을 때 
			else if(c >= middleRC) {
				answer += (nowLen * nowLen / 4);
				c -= middleRC;
			} 
			
			// 해당 값을 2로 나눠준다.
			nowLen /= 2;
		}
		
		// 위의 과정을 거치면 답을 구할 수 있다.
		System.out.println(answer);
	}
}
