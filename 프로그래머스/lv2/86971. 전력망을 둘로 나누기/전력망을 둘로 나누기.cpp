#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    
    for(int x = 0; x < wires.size(); x++)
    {
        vector<vector<int>> links(n+1, vector<int>()); vector<bool> isCheck(n+1, false);
        
        for(int i = 0; i < wires.size(); i++)
        {
            if(i == x) continue;
            links[wires[i][0]].push_back(wires[i][1]);
            links[wires[i][1]].push_back(wires[i][0]);
        }
          
        vector<int> val(2, 0); int idx = 0;
        for(int c = 1; c <= n; c++)
        {
            if(isCheck[c]) continue;
            
            vector<int> nextVec;
            nextVec.push_back(c); isCheck[c] = true; ++val[idx];
            
            while(nextVec.size() != 0)
            {
                vector<int> tmpVec;
                
                for(int i = 0; i < nextVec.size(); i++)
                {
                    int t = nextVec[i];
                    for(int j = 0; j < links[t].size(); j++)
                    {
                        if(!isCheck[links[t][j]]) { tmpVec.push_back(links[t][j]); isCheck[links[t][j]] = true; ++val[idx]; }
                    }
                }
                
                nextVec = tmpVec;
            }
            
            ++idx;
        }
        
        if(abs(val[1] - val[0]) < answer) answer = abs(val[1] - val[0]);
    }
    
    return answer;
}