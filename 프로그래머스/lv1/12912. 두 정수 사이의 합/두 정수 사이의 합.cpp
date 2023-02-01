#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a > b) { int t = a; a = b; b = t; }
    
    for(; a <= b; a++)
    {
        answer += a;
    }
    return answer;
}