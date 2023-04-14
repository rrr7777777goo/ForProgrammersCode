#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int nN;

struct Data
{
    int val;
    Data(int v) { val = v; }
    
    bool operator<(const Data &d) const
    {
        int c1 = abs(val - nN), c2 = abs(d.val - nN);
        if(c1 == c2) return val < d.val;
        else return c1 > c2;
    }
};

vector<int> solution(vector<int> numlist, int n) {
    nN = n;
    
    priority_queue<Data> qu;
    
    for(int i = 0; i < numlist.size(); i++) qu.push(Data(numlist[i]));
    
    vector<int> answer;
    
    while(!qu.empty())
    {
        answer.push_back(qu.top().val);
        qu.pop();
    }
    
    return answer;
}