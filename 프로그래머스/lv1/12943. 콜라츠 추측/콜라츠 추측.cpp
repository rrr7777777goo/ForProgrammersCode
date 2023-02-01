#include <string>
#include <vector>

using namespace std;

int solution(int num) {
   
    int count = 0;
    long long n = num;
    
    while(n != 1 && count < 500)
    {
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        ++count;
    }
    
    if(count >= 500) return -1;
    else return count;
}