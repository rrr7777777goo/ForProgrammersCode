#include <string>
#include <vector>
#include <queue>
using namespace std;

struct I_V
{
    int i, v;
    I_V(int i, int v) { this->i = i; this->v = v;}
    
    bool operator<(const I_V &iv) const
    {
        return v < iv.v;
    }
};

vector<int> solution(vector<int> array) {
    vector<int> answer(2,0);
    priority_queue<I_V> qu;
    for(int i = 0; i < array.size(); i++) qu.push(I_V(i, array[i]));
    answer[1] = qu.top().i; answer[0] = qu.top().v;
    return answer;
}