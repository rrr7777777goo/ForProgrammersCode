using namespace std;

long long j[2001];

long long solution(int n) {
    j[1] = 1; j[2] = 2;
    for(int i = 3; i <= n; i++) j[i] = (j[i-1] + j[i-2]) % 1234567;
    return j[n];
}