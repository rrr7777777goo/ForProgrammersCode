#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;  
    int cnt = 0, len = 0, len_elec = 2 * w + 1;
    int startPoint = 1;
    for(int i = 0; i < stations.size(); i++)
    {
        int endPoint = stations[i] - (w+1);
        
        if(endPoint >= startPoint)
        {
            len = endPoint - startPoint + 1;
            
            cnt = len / len_elec;
            if(len % len_elec > 0) ++cnt;
            answer += cnt;
        }
        startPoint = stations[i] + (w+1);
        
        if(startPoint > n) break;
    }
    
    if(startPoint <= n)
    {
        len = n - startPoint + 1;
            
        cnt = len / len_elec;
        if(len % len_elec > 0) ++cnt;
        answer += cnt;
    }
    
    return answer;
}