#include <string>
#include <vector>
#include <queue>
using namespace std;

struct RT
{
    int s, e;
    RT(int s, int e) { this->s = s; this->e = e; }
    
    bool operator<(const RT &rt) const
    {
        if(s == rt.s)
        {
            int len1 = e - s + 1, len2 = rt.e - rt.s + 1;
            return len1 > len2;
        }
        else return s > rt.s;
    }
};

int solution(vector<vector<int>> routes) {
    priority_queue<RT> qu; 
    
    for(int i = 0; i < routes.size(); i++) qu.push(RT(routes[i][0], routes[i][1]));
    
    int answer = 1, sPoint = sPoint = qu.top().s, ePoint = qu.top().e; qu.pop();
    
    while(!qu.empty())
    {
        RT r = qu.top(); qu.pop();
        if(r.s > ePoint)
        {
            sPoint = r.s;
            ePoint = r.e;
            ++answer;
        }
        else
        {
            sPoint = r.s;
            if(r.e < ePoint) ePoint = r.e;
        }
    }
    return answer;
}