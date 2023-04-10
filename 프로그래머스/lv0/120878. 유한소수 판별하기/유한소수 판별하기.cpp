#include <string>
#include <vector>
using namespace std;

vector<int> sosu;
bool isNotSoSu[1001];

int solution(int a, int b) {
    
    for(int i = 2; i <= 1000; i++)
    {
        if(!isNotSoSu[i])
        {
            sosu.push_back(i);
            for(int x = i+i; x <= 1000; x += i)
            {
                isNotSoSu[x] = true;
            }
        }
    }
    
    while(true)
    {
        bool isDiv = false;
        for(int i = 0; i < sosu.size(); i++)
        {
            if(sosu[i] > a || sosu[i] > b) break;
            
            if(a % sosu[i] == 0 && b % sosu[i] == 0)
            {
                a /= sosu[i]; b /= sosu[i];
                isDiv = true; break;
            }
        }
        
        if(!isDiv) break;
    }

    int answer = 1;
    
    while(b > 1)
    {
        if(b % 2 == 0) { b /= 2; continue; }
        if(b % 5 == 0) { b /= 5; continue; }
        
        answer = 2; break;
    }
    
    return answer;
}