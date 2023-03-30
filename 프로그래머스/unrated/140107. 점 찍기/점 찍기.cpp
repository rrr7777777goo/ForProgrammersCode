#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    long long dD = (long long)d * (long long)d;
    
    for(long long y = 0; y <= d; y += k)
    {
        int t = sqrt(dD - (y*y));
        answer += t/k;
        ++answer;
    }
    
    return answer;
}


 

/*

x ㅁ ㅁ ㅁ ㅁ
x ㅁ ㅁ ㅁ ㅁ
x ㅁ ㅁ ㅁ ㅁ
x ㅁ ㅁ ㅁ ㅁ
x x x x x

*/