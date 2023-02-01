#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool isAlreadyCheck[201];
vector<int> nextPC[201];

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < computers.size(); i++)
    {
        for(int x = 0; x < computers[i].size(); x++)
        {
            if(i == x) continue;
            if(computers[i][x]) nextPC[i+1].push_back(x+1);
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(isAlreadyCheck[i]) continue;
        
        ++answer;
        isAlreadyCheck[i] = true;
        
        set<int> set_nextPC;
        set_nextPC.insert(i);
        
        while(!set_nextPC.empty())
        {
            set<int> tmp_nextPC;
            
            for(set<int>::iterator it = set_nextPC.begin(); it != set_nextPC.end(); it++)
            {
                int r = *it;
                for(int a = 0; a < nextPC[r].size(); a++)
                {
                    if(isAlreadyCheck[nextPC[r][a]]) continue;
                    isAlreadyCheck[nextPC[r][a]] = true;
                    tmp_nextPC.insert(nextPC[r][a]);
                }
            }
            
            set_nextPC = tmp_nextPC;
        }
    }
    
    return answer;
}