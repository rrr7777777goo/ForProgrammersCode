#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    if(s/n == 0) return vector<int>(1, -1);
    
    vector<int> answer;
    
    int fir = s/n;
    int idx_plusStart = n - (s%n);
    
    for(int i = 0; i < n; i++)
    {
        if(i >= idx_plusStart) answer.push_back(fir+1);
        else answer.push_back(fir);
    }
    
    return answer;
}