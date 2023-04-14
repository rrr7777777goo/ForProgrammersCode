#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Data
{
    int sum, idx;
    Data(int e, int m, int i) { sum = e + m; idx = i; }
    
    bool operator<(const Data &d) const { return sum < d.sum; }
};

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size(), 0);
    
    priority_queue<Data> qu;
    for(int i = 0; i < score.size(); i++) qu.push(Data(score[i][0], score[i][1], i));
    
    Data d = qu.top(); qu.pop();
    int rank = 1, cnt = 1, currentScore = d.sum;
    answer[d.idx] = rank; 
    
    while(!qu.empty())
    {
        d = qu.top(); qu.pop();
        
        if(d.sum < currentScore) { rank += cnt; currentScore = d.sum; cnt = 1; }
        else if(d.sum == currentScore) { ++cnt; }
        
        answer[d.idx] = rank;
    }
    
    return answer;
}