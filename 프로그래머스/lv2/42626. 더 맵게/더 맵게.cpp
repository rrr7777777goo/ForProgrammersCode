#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, greater<long long>> qu;
    
    for(int i = 0; i < scoville.size(); i++) qu.push(scoville[i]);
    
    if(qu.top() >= K) return 0;
    
    int cnt = 0; long long val = 0;

    while(qu.size() > 1)
    {
        ++cnt;
        long long fir = qu.top(); qu.pop(); long long seco = qu.top(); qu.pop();
        val = fir + seco * 2;
        qu.push(val);
        if(qu.top() >= K) return cnt;
    }
    
    return -1;
}