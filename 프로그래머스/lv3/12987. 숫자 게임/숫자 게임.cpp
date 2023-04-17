#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    priority_queue<int> qA, qB; 
    for(int i = 0; i < A.size(); i++)
    {
        qA.push(A[i]); qB.push(B[i]);
    }

    deque<int> dB;
    while(!qB.empty())
    {
        dB.push_back(qB.top()); qB.pop();
    }
    
    while(!qA.empty())
    {
        int a = qA.top(); qA.pop();
        
        if(a < dB.front()) { ++answer; dB.pop_front(); }
        else { dB.pop_back(); }
        
    }
    
    return answer;
}