#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Dt
{
    int idx, value;
    
    Dt(int i, int v) { idx = i; value = v; }
    
    bool operator<(const Dt & d) const
    {
        if(value == d.value) idx > d.idx;
        return value < d.value;
    }
};

vector<int> solution(vector<int> answers) {
    vector<int> c1; c1.push_back(1); c1.push_back(2); c1.push_back(3); c1.push_back(4); c1.push_back(5);
    vector<int> c2; c2.push_back(2); c2.push_back(1); c2.push_back(2); c2.push_back(3);
                    c2.push_back(2); c2.push_back(4); c2.push_back(2); c2.push_back(5);
    vector<int> c3; c3.push_back(3); c3.push_back(3); c3.push_back(1); c3.push_back(1); c3.push_back(2);
                    c3.push_back(2); c3.push_back(4); c3.push_back(4); c3.push_back(5); c3.push_back(5);
    
    vector<int> score(4, 0), idx(4, 0);
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == c1[idx[1]]) ++score[1]; if(answers[i] == c2[idx[2]]) ++score[2]; if(answers[i] == c3[idx[3]]) ++score[3];
        
        idx[1] = (idx[1] + 1) % c1.size(); idx[2] = (idx[2] + 1) % c2.size(); idx[3] = (idx[3] + 1) % c3.size();
        
    }

    priority_queue<Dt> qu; for(int i = 1; i <= 3; i++) { qu.push(Dt(i, score[i])); }
    
    vector<int> answer;
    
    answer.push_back(qu.top().idx); qu.pop();
    for(int cnt = 0; cnt < 2; cnt++) if(score[answer[0]] == qu.top().value) { answer.push_back(qu.top().idx); qu.pop(); }
    
    return answer;
}