#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = -100001;
    
    long long tmp_sum_001 = -100001, tmp_sum_002 = -100001;
    long long buho_001 = 1, buho_002 = -1;
    
    for(int i = 0; i < sequence.size(); i++)
    {
        long long t1 = sequence[i] * buho_001, t2 = sequence[i] * buho_002;
        
        if(tmp_sum_001 + t1 < t1) { tmp_sum_001 = t1; }
        else tmp_sum_001 += t1;
        
        if(tmp_sum_002 + t2 < t2) { tmp_sum_002 = t2; }
        else tmp_sum_002 += t2;
        
        if(tmp_sum_001 > answer) answer = tmp_sum_001;
        if(tmp_sum_002 > answer) answer = tmp_sum_002;
        
        buho_001 *= -1; buho_002 *= -1;
    }
    
    
    return answer;
}