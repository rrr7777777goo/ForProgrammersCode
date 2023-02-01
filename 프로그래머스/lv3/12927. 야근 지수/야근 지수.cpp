#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Work
{
    int i;
    long long work;
    
    Work(int i, long long w) { this->i = i; work = w; }
    
    bool operator<(const Work & w) const
    {
        if(work == w.work) return i > w.work;
        else return work < w.work;
    }
};

long long sum;
priority_queue<Work> qu;

long long solution(int n, vector<int> works) {
    
    for(int i = 0; i < works.size(); i++) { sum += works[i]; qu.push(Work(i, works[i])); }
    
    if(sum <= n) return 0;
    
    for(int i = 0; i < n; i++) { Work z = qu.top(); qu.pop(); --z.work; qu.push(z); }
    
    long long answer = 0;
    while(!qu.empty()) { Work z = qu.top(); qu.pop(); answer += pow(z.work, 2); }
    return answer;
}