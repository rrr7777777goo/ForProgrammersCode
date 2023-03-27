#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);
    
    if(n > m) { int tmp = m; m = n; n = tmp; }
    
    for(int i = n; i >= 1; i--) if(m % i == 0 && n % i == 0) { answer[0] = i; break; }
    
    long long mul = n * m;
    answer[1] = mul / answer[0];
    return answer;
}