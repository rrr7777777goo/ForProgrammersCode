#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Data
{
    int idx, val;
    
    Data(int i, int v) { idx = i; val = v; }
    
    bool operator<(const Data &d) const
    {
        if(val == d.val) return idx < d.idx;
        return val < d.val;
    }
};

int solution(vector<int> stones, int k) {
    priority_queue<int, vector<int>, greater<int>> qu_answer;
    
    priority_queue<Data> dataQ;
    for(int i = 0; i < k; i++) dataQ.push(Data(i, stones[i]));
    
    qu_answer.push(dataQ.top().val);
    
    int firstIdx = 0;
    for(int i = k; i < stones.size(); i++)
    {
        ++firstIdx;
        dataQ.push(Data(i, stones[i]));
        
        while(true)
        {
            if(dataQ.top().idx >= firstIdx) { qu_answer.push(dataQ.top().val); break; }
            else dataQ.pop();
        }
    }

    return qu_answer.top();
}