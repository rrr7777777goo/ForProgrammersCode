#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Data001
{
    int i1, i2, idx, sum;
    Data001(int _i1, int _i2, int dx) {i1 = _i1; i2 = _i2; idx = dx; sum = _i1 + _i2; };
    
    bool operator<(const Data001 &d1) const
    {
        if(i1 == d1.i1) return i2 > d1.i2;
        else return i1 < d1.i1;
    }
    
    bool operator>(const Data001 &d1) const
    {
        if(sum == d1.sum) return idx > d1.idx;
        return sum < d1.sum;
    }
};

int solution(vector<vector<int>> scores) {
    
    
    priority_queue<Data001> qu001;
    for(int i = 0; i < scores.size(); i++) qu001.push(Data001(scores[i][0], scores[i][1], i));
    
    priority_queue<Data001, vector<Data001>, greater<Data001>> qu002;
    
    int maxI1 = qu001.top().i1, maxI2 = qu001.top().i2;
    qu002.push(qu001.top()); qu001.pop();
    
    while(!qu001.empty())
    {
        Data001 chkD1 = qu001.top(); qu001.pop();
        if(maxI1 > chkD1.i1 && maxI2 > chkD1.i2)
        {
            if(chkD1.idx == 0) { return -1; }
            else continue;
        }
        else { maxI1 = chkD1.i1; maxI2 = maxI2 >= chkD1.i2 ? maxI2 : chkD1.i2; qu002.push(chkD1); }
    }
    
    int rnk = 1, cnt = 1, maxSum = -1;
    
    while(!qu002.empty())
    {
        int tmpSum = qu002.top().sum, tmpIdx = qu002.top().idx; qu002.pop();
        
        if(maxSum == -1) { maxSum = tmpSum; }
        else { if(maxSum == tmpSum) { ++cnt; } else { rnk += cnt; cnt = 1; } }
        
        if(tmpIdx == 0) { return rnk; }
    }
    
    return -1;
}
