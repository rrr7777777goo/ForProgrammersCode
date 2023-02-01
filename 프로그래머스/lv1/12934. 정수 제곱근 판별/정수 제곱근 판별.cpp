#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {  
    long long sqr = sqrt(n);
    
    if(sqr*sqr == n) return (sqr+1) * (sqr+1);
    else return -1;
}