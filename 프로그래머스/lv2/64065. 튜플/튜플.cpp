#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Num
{
    int idx, cnt;
    
    Num(int i, int c) { idx = i; cnt = c; }
    bool operator<(const Num &n) const { return cnt < n.cnt; }
};
priority_queue<Num> qu;

map<int, int>ma;
typedef map<int, int>::iterator iter;

vector<int> solution(string s) {
    vector<int> answer;
    
    string tmp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            tmp += s[i];
        }
        else
        {
            if(tmp.compare("") != 0)
            {
                ++ma[stoi(tmp)];
                tmp = "";
            }
        }
    }
    
    for(iter i = ma.begin(); i != ma.end(); i++) qu.push(Num(i->first,i->second));
    
    while(!qu.empty())
    {
        answer.push_back(qu.top().idx);
        qu.pop();
    }
    
    return answer;
}