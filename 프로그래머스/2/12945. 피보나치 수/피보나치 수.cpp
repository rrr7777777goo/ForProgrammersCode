#include <string>
#include <vector>
using namespace std;

int pibo[100001];

int solution(int n) {
    pibo[1] = 1; for(int i = 2; i <= n; i++) pibo[i] = (pibo[i-1] + pibo[i-2]) % 1234567;
    return pibo[n];
}