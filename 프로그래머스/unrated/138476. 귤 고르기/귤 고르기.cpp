#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Data
{
    int idx, val;
    Data(int i, int v) { idx = i; val = v; }
    
    bool operator<(const Data & d) const
    {
        if(val == d.val) return idx > d.idx;
        else return val < d.val;
    }
};

map<int, int> ma;
typedef map<int, int>::iterator iter;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int i = 0; i < tangerine.size(); i++) ++ma[tangerine[i]];
    
    priority_queue<Data> qu; vector<Data> vec;
    
    for(iter it = ma.begin(); it != ma.end(); it++) qu.push(Data(it->first, it->second));
    
    while(!qu.empty()) { vec.push_back(qu.top()); qu.pop(); }
    
    int current = 0, cnt = 0, iI = 0;
    while(cnt < k)
    {
        if(current != vec[iI].idx) { current = vec[iI].idx; ++answer; }
        
        --vec[iI].val; if(vec[iI].val == 0) ++iI;
        
        ++cnt;
    }
    
    return answer;
}