#include <string>
#include <vector>
using namespace std;

vector<int> v_plus;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    v_plus = vector<int>(speeds.size(), 0);
    
    int i = 0;
    while(i < speeds.size())
    {
        for(int x = 0; x < speeds.size(); x++) v_plus[x] += speeds[x];
            
        if(progresses[i] + v_plus[i] >= 100)
        {
            int cnt = 0;
            while(progresses[i] + v_plus[i] >= 100) { ++i; ++cnt; if(i == speeds.size()) break; }
            answer.push_back(cnt);
        }
    }
    
    return answer;
}