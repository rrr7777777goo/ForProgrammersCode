#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Stage
{
    int idx_stage;
    long long bza, bmo;
    
    Stage(int i, int za, int mo) { idx_stage = i; bza = za; bmo = mo; }
    
    bool operator<(const Stage& s) const
    {
        long long me = bza * s.bmo;
        long long you = s.bza * bmo;
        
        if(me == you) return idx_stage > s.idx_stage;
        else return me < you;
    }
};

map<int, int> bunza;
map<int, int> bunmo;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i = 0; i < stages.size(); i++)
    {
        int t = stages[i];
        ++bunza[t]; for(int z = t; z >= 1; z--) ++bunmo[z];
    }
    
    priority_queue<Stage> qu;
    for(int i = 1; i <= N; i++)
    {
        int za = bunza[i], mo = bunmo[i];
        if(mo == 0) qu.push(Stage(i, 0, 1));
        else qu.push(Stage(i, za, mo));
    }
    
    while(!qu.empty()) { answer.push_back(qu.top().idx_stage); qu.pop(); }
    
    return answer;
}