#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Paper
{
    int idx, prior;
    
    Paper(int i, int p) { idx = i; prior = p; };
};
queue<Paper> qu;

vector<bool> isAlreadyUsed(100, 0);

int solution(vector<int> priorities, int location) {
    for(int i = 0; i < priorities.size(); i++) qu.push(Paper(i, priorities[i]));
    
    int ans = 1;
    while(true)
    {
        int iI = qu.front().idx;
        int p = qu.front().prior;
        
        bool isStart = true;
        for(int i = 0; i < priorities.size(); i++)
        {
            if(i == iI || isAlreadyUsed[i]) continue;
            else if(p < priorities[i])
            {
                qu.push(Paper(iI, p)); qu.pop();
                isStart = false;
                break;
            } 
        }
        
        if(isStart)
        {
            if(iI == location) break;
            isAlreadyUsed[iI] = true;
            qu.pop();
            ++ans;
        } 
    }
    return ans;
}