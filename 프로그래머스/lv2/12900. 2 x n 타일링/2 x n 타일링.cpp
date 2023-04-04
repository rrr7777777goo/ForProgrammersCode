#include <string>
#include <vector>
using namespace std;

int val[60001];

int solution(int n) {
    val[1] = 1; val[2] = 2;
    
    for(int i = 3; i <= n; i++)
    {
        val[i] = (val[i-1] + val[i-2]) % 1000000007;
    }
    
    return val[n];
}