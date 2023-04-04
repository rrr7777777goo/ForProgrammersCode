#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long iI = begin; iI <= end; iI++)
    {
        if(iI == 1) { answer.push_back(0); continue; }
        
        vector<int> tmp_vec; bool isComplete = false;
        
        for(int i = 2; i <= sqrt(iI); i++)
        {
            if(iI % i == 0)
            {
                if(iI / i <= 10000000) { answer.push_back(iI / i); isComplete = true; break; }
                else tmp_vec.push_back(i);
            }
        }
        
        if(!isComplete)
        {
            if(tmp_vec.size() == 0) answer.push_back(1);
            else answer.push_back(tmp_vec[tmp_vec.size() - 1]);
        }
    }
    
    return answer;
}