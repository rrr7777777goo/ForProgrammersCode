#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    priority_queue<int> numQ;
    
    int zari = -1;
    while(n > 0) { numQ.push(n%10); n /= 10; ++zari; }
    
    while(zari >= 0)
    {
        int z = numQ.top();
        
        answer = answer + (z * pow(10, zari));
        numQ.pop();
        --zari;
    }

    return answer;
}