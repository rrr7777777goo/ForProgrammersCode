#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> cores) {
    
    if(n <= cores.size()) return n;
    
    int startTime = 1, endTime = 250000000;
    
    while(startTime < endTime)
    {
        int middleTime = (startTime + endTime) / 2;
        long long sum = cores.size();
        for(int i = 0; i < cores.size(); i++) sum += middleTime / cores[i];
        if(sum >= n) endTime = middleTime; else startTime = middleTime+1;
    }
    
    --startTime;
    
    int chksum = cores.size();
    
    for(int i = 0; i < cores.size(); i++) chksum += startTime / cores[i];
    
    ++startTime;
    
    int answer = 0;
    for(int i = 0; i < cores.size(); i++)
    {
        if(startTime % cores[i] == 0) ++chksum;
        if(chksum == n) { answer = i+1; break; }
    }
    
    return answer;
}