#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int D, L, N; cin >> D >> L >> N;
         
        long long sum = 0;
        for(int i = 0; i < N; i++)
        {
            long long damage = D + D * i * L/ 100;
            sum += damage;
        }
        
        cout << '#' << test_case << ' ' << sum << '\n';
	}
	return 0;
}