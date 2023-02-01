#include <string>
#include <vector>
#include <iostream>
using namespace std;

int start_idx = -1;
int maxi;
vector<int> list_NM(10001, 0);

int solution(vector<int> citations) {
    int answer = 0;
    
    int sum = citations.size();
    
    for(int i = 0; i < citations.size(); i++)
    {
        list_NM[citations[i]] += 1;
        maxi += 1;
        if(start_idx < citations[i]) start_idx = citations[i];
    }
    
    int tmp = 0;
    while(start_idx >= 0)
    {
        tmp += list_NM[start_idx]; maxi -= list_NM[start_idx];
        if(tmp >= start_idx && maxi <= start_idx) break;
        --start_idx;
    }
    
    return start_idx;
}