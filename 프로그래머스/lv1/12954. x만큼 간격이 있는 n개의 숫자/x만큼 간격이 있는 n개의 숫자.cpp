#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    int count = 1; long long X = x;
    while(count <= n)
    {
        answer.push_back(X);
        ++count; if(count > n) break;
        X += x;
    }
    return answer;
}