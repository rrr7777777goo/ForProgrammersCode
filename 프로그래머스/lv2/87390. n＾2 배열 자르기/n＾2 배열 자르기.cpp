#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i <= right; i++)
    {
        long long mok = i / n + 1;
        long long namuzi = i % n + 1;
        
        if(mok > namuzi) answer.push_back(mok);
        else answer.push_back(namuzi); 
    }
    
    return answer;
}