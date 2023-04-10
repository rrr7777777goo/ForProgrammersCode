#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Data { int idx, val; Data(int i, int v) { idx = i; val = v;} };

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++)
    {
        answer.push_back((prices.size() - 1) - i);
    }
    
    stack<Data> sta; sta.push(Data(0, prices[0]));
    for(int i = 0; i < prices.size(); i++)
    {
        while(!sta.empty())
        {
            if(sta.top().val > prices[i]) { answer[sta.top().idx] = i - sta.top().idx; sta.pop(); }
            else break;
        }
        
        sta.push(Data(i, prices[i]));
    }
    
    
    while(!sta.empty()) { answer[sta.top().idx] = (prices.size()-1) - sta.top().idx; sta.pop(); }
    
    return answer;
}