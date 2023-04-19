#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isCheck[20000];
bool isLink[20000][20000];
int len[20000];

int solution(int n, vector<vector<int>> edge) {
    for(int i = 0; i < edge.size(); i++)
    {
        isLink[edge[i][0]-1][edge[i][1]-1] = true;
        isLink[edge[i][1]-1][edge[i][0]-1] = true;
    }
    
    for(int i = 1; i < n; i++) len[i] = 50000;
    
    len[0] = 0; isCheck[0] = true; 
    
    int cIdx = 0;
    while(true)
    {
        for(int i = 0; i < n; i++)
        {
            if(isCheck[i]) continue;
            if(isLink[cIdx][i]) { if(len[cIdx] + 1 < len[i]) { len[i] = len[cIdx] + 1; } }
        }
        
        int minIdx = -1, minLen = 50000;
        for(int i = 0; i < n; i++)
        {
            if(isCheck[i]) continue;
            if(len[i] < minLen) { minIdx = i; minLen = len[i]; }
        }
        if(minIdx == -1) break;
        else { isCheck[minIdx] = true; cIdx = minIdx; }
    }
    
    
    int answer = 1, maxLen = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(len[i] == 50000) continue;
        
        if(len[i] > maxLen) { answer = 1; maxLen = len[i]; }
        else if (len[i] == maxLen) { ++answer; }
    }
    
    return answer;
}