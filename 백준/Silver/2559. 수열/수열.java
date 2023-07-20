import java.util.*;

/**
 * @author 조근호
 * 
 * <pre>
 * 백준 2559 수열
 * https://www.acmicpc.net/problem/2559
 * 수열을 입력받은 후 일정 길이의 부분수열에 들어있는 값들을 더할 때 가장 큰 값은 얼마인지 구하는 문제
 * 처음엔 맨 왼쪽부터 일정길이만큼의 값들을 더한다음 그 값을 최대값으로 설정하고
 * 그 다음부터 앞에 새로운 값을 하나 더하면 수열의 맨 처음 값을 하나 빼는 식으로
 * 수열을 조사하고 만약 저장된 최댓값보다 더 크다면 그 값을 최대값으로 갱신해준다.
 * 그런식으로 새로 바뀌게 된 값을 확인하면서 최대값을 갱신해나가면
 * 원하는 답을 얻을 수 있다.
 * 메모리 113100kb
 * 실행시간 868ms 
 * </pre>
 */

public class Main {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in); // Scanner 객체 생성
		// N : 수열의 길이 / K : 부분수열의 길이
                           int N = sc.nextInt(), K = sc.nextInt();
		
		// 수열 생성
		int arr[] = new int[N];
		
		// 수열에 값을 순서대로 넣는다.
		for(int i = 0; i < N; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		// currentValue : 현재 부분수열의 합
		// frontIdx : 부분수열의 맨 처음 부분을 나타내는 인덱스
		// answer : 부분수열 합의 최대값을 저장할 변수
		int currentValue = 0, frontIdx = 0, answer = 0;
		
		// 수열을 맨 왼쪽부터 순서대로 조사한다.
		for(int i = 0; i < N; i++)
		{
			currentValue += arr[i]; // 새로 조사하는 곳의 값을 더한다.

			// 현재 i값이 K-1이라면 원하는 부분수열의 길이만큼
			// 값을 조사했음을 의미한다. 따라서, 일단 현재 값을 최대합이라고 설정한뒤 for문을 더 진행하면서 갱신해주면 된다.
			if(i == K-1) answer = currentValue;
			// 현재 i값이 K보다 크다면 부분수열의 길이를 넘지 않게 부분수열의 맨 왼쪽 값을 currentValue에서 빼준다.
			// 그리고 맨 왼쪽을 나타내는 변수는 후위연산자를 통해 값을 1 올려주고
			// 만약 현재부분수열의 합이 answer보다 크다면 값을 갱신해준다.
			else if(i >= K) 
			{
				currentValue -= arr[frontIdx++];
				if(answer < currentValue) answer = currentValue;
			}
		}
		
		// 위의 for문을 모두 마치고 나면 부분수열 합의 최대값이 answer에 저장되게 되니 그 값을 출력해주면 된다.
		System.out.println(answer);
	}
}