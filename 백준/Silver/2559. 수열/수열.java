import java.util.*;

public class Main {
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), K = sc.nextInt();
		
		int arr[] = new int[N];
		
		for(int i = 0; i < N; i++)
		{
			arr[i] = sc.nextInt();
		}
		
		int currentValue = 0, frontIdx = 0, answer = 0;
		
		for(int i = 0; i < N; i++)
		{
			currentValue += arr[i];

			if(i >= K)
			{
				currentValue -= arr[frontIdx++];
				if(answer < currentValue) answer = currentValue;
			}
			else if(i == K-1) answer = currentValue;
		}
		
		System.out.println(answer);
	}
}