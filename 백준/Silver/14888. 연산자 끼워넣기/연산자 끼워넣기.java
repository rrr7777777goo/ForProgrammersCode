import java.util.*;

/**
 * 
 * @author 조근호
 * 
 * <pre>
 * 백준 14888 연산자 끼워넣기
 * https://www.acmicpc.net/problem/14888
 * N개로 이루어진 수열과 총합 N-1개의 + - * / 연산자가 주어질 때
 * 조합해서 만들 수 있는 최대값과 최소값을 구하는 문제
 * 조합해서 나오는 값은 -10억 이상 10억 이하이며 N의 최대값은 11이다.
 * 재귀함수를 이용해서 완전탐색을 하면 원하는 답을 얻을 수 있다.
 * 메모리 19136kb
 * 실행시간 216ms 
 * </pre>
 */


public class Main {
	
	// N값(몇 개의 숫자가 주어지는지 의미)
	static int N;
	// 최대값을 나타내는 변수, 연산자 조합으로 나올 수 있는 가장 작은값을 초기값으로 설정해준다.
	static int maxi = -1000000000;
	// 최소값을 나타내는 변수, 연산자 조합으로 나올 수 있는 가장 큰값을 초기값으로 설정해준다.
	static int mini = 1000000000;
	
	// 주어지는 숫자를 저장할 배열
	static int[] arr_A = new int[11];
	
	// 연산자를 조합해서 결과값을 얻어내는 함수
	// currentValue : 현재 저장된 연산값
	// currentIndex : 현재 연산자를 이용해서 기존의 값(currentValue)에 덧셈 or 뺄셈 or 곱셉 or 나눗셈을 할 값
	// count_plus : 현재 남아있는 +의 개수
	// count_minus : 현재 남아있는 -의 개수
	// count_mul : 현재 남아있는 *의 개수
	// count_div : 현재 남아있는 /의 개수
	static void Find_Max_Min(int currentValue, int currentIndex, int count_plus, int count_minus, int count_mul, int count_div) {
		
		// 만약 currentIndex의 값이 N이라면 지금까지 존재했던 모든 값들을 연산에 사용했음을 의미하므로
		// 최대값, 최소값 여부를 파악한뒤 갱신해주고 return을 이용해서 함수를 종료해준다.
		if (currentIndex == N) {
			// currentIndex이 최소값 인지 확인하고 맞다면 갱신해준다.
			if (currentValue < mini) {
				mini = currentValue;
			}
			// currentIndex이 최대값 인지 확인하고 맞다면 갱신해준다.
			if (currentValue > maxi) {
				maxi = currentValue;
			} 
			// 함수를 바로 종료시켜준다.
			return; 
		}
		
		// nextIndex : currentIndex 다음 인덱스를 저장할 변수
		int nextIndex = currentIndex + 1;
		
		// + 연산자가 아직 남아있다면 실행해준다.
		// 이 때 매개변수를 입력할 때 currentValue 부분에는 arr_A[currentIndex]을 더해주고
		// currentIndex 부분에는 nextIndex를 넣어주고
		// count_plus의 개수에 1을 빼준다.
		// 밑의 다른 연산자 부분도 이런식으로 작성해주면 된다.
		if (count_plus != 0) {
			Find_Max_Min(currentValue + arr_A[currentIndex], nextIndex, count_plus - 1, count_minus, count_mul, count_div);
		}

		// - 연산자가 아직 남아있다면 실행해준다.
		if (count_minus != 0) {
			Find_Max_Min(currentValue - arr_A[currentIndex], nextIndex, count_plus, count_minus - 1, count_mul, count_div);
		}

		// * 연산자가 아직 남아있다면 실행해준다.
		if (count_mul != 0) {
			Find_Max_Min(currentValue * arr_A[currentIndex], nextIndex, count_plus, count_minus, count_mul - 1, count_div);
		}

		// / 연산자가 아직 남아있다면 실행해준다.
		if (count_div != 0) {
			Find_Max_Min(currentValue / arr_A[currentIndex], nextIndex, count_plus, count_minus, count_mul, count_div - 1);
		}
	}
	
	public static void main(String[] args) {
		// Scanner 객체 생성
		Scanner sc = new Scanner(System.in); 
		
		// N값을 입력받는다.
		N = sc.nextInt();
		
		// 배열에 순서대로 값을 입력받는다.
		for(int i = 0; i < N; i++) {
			arr_A[i] = sc.nextInt();
		}
		
		// 각 부호의 개수를 저장할 배열 인덱스 0번부터 3번까지 순서대로 + - * / 를 의미한다.
		int[] count_buho = new int[4];
		
		// 부호의 개수를 순서대로 입력받는다.
		for(int i = 0; i < 4; i++) {
			count_buho[i] = sc.nextInt();
		}
		
		// 완전탐색을 시작한다. 이걸 모두 마치고나면 원하는 값을 얻을 수 있다. (함수에 대한 설명은 위의 함수에 써진 주석 참고)
		Find_Max_Min(arr_A[0], 1, count_buho[0], count_buho[1], count_buho[2], count_buho[3]);
		
		// 위의 함수를 모두 돌리면 문제에서 주어진 조건대로 최대값, 최소값을 출력해준다.
		System.out.printf("%d %d%n", maxi, mini);
	}
}
