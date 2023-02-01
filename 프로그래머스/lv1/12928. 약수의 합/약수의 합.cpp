#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    double maxi = sqrt(n);
    for(int i = 1; (double) i <= maxi; i++)
    {
        if((i*i) == n) answer += i;
        else if(n%i == 0) { answer += i; answer += (n / i); }
    }
    
    return answer;
}