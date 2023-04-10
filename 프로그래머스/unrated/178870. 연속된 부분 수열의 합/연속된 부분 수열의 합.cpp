#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0); answer[0] = 0, answer[1] = 3333333;
    
    int s = 0, e = 0, preE = -1, sum = 0;
    
    while(e < sequence.size() && s <= e)
    {
        if(preE != e) { sum += sequence[e]; preE = e; }
        
        if(sum < k) { ++e; }
        else if(sum > k) { sum -= sequence[s]; ++s; }
        else if (sum == k)
        {
            int len1 = answer[1] - answer[0] + 1, len2 = e - s + 1;
            
            if(len2 < len1) { answer[0] = s; answer[1] = e; }
            
            ++e; preE = e-1;
            sum -= sequence[s]; ++s;
        }
    }
    
    return answer;
}