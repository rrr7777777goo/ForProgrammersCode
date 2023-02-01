#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int valN = 1, sum = 0, pplus = 1;
    
    while(true)
    {
        int tmp = n - sum;
        if(tmp % valN == 0)
        {
            if(tmp / valN <= 0) break;
            else ++answer;
        }
        
        ++valN;
        sum += pplus;
        ++pplus;
    }
    
    return answer;
}