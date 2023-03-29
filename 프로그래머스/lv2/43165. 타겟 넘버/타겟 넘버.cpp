#include <string>
#include <vector>
#include <queue>
using namespace std;

// 깊이우선탐색 (DFS)
vector<int> num;
int len, tar, ans;

void Add(int cnt, int sum)
{
    if(cnt == len)
    {
        if(sum == tar) ++ans;
    }
    else
    {
        Add(cnt + 1, sum + num[cnt]);
        Add(cnt + 1, sum + (-1 * num[cnt]));
    }
}

int solution(vector<int> numbers, int target) {
    num = numbers;
    len = numbers.size(); tar = target;
    
    Add(0, 0);
    
    return ans;
}

/*
// 너비우선탐색 (BFS)
int solution(vector<int> numbers, int target)
{
    vector<int> isAlreadyCheck; vector<int> resetVec(2001, 0);
    queue<int> qu; qu.push(0);
    
    for(int i = 0; i < numbers.size(); i++)
    {
        isAlreadyCheck = resetVec;
        
        queue<int> tqu;
        
        while(!qu.empty())
        {
            int t = qu.front(); qu.pop();
            
            int pl = t + numbers[i], mi = t - numbers[i];
            if(!isAlreadyCheck[pl + 1000]) { tqu.push(pl); isAlreadyCheck[pl + 1000]; }
            if(!isAlreadyCheck[mi + 1000]) { tqu.push(mi); isAlreadyCheck[mi + 1000]; }
        }
        
        qu = tqu;
    }
    
    int answer = 0;
    
    while(!qu.empty()) { if(qu.front() == target) ++answer; qu.pop(); }
    
    return answer;
}
*/