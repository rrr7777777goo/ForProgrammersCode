#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

map<int,bool> ma[100000];
typedef map<int, bool>::iterator iter;

bool isCheck[100000];
map<int,int> val;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    --destination;
    
    for(int i = 0; i < roads.size(); i++)
    {
        ma[roads[i][0]-1][roads[i][1]-1] = true;
        ma[roads[i][1]-1][roads[i][0]-1] = true;
    }
    
    queue<int> currentQu; int len = 0; 
    val[destination] = len; isCheck[destination] = true;
    currentQu.push(destination);
    
    while(!currentQu.empty())
    {
        queue<int> nextQu; ++len;
        while(!currentQu.empty())
        {
            int cIdx = currentQu.front(); currentQu.pop();
            for(iter it = ma[cIdx].begin(); it != ma[cIdx].end(); it++)
            {
                if(!isCheck[it->first])
                {
                    nextQu.push(it->first);
                    val[it->first] = len; isCheck[it->first] = true;
                }
            }
        }
        currentQu = nextQu;
    }
    
    vector<int> answer(sources.size(), -1);
    for(int i = 0; i < sources.size(); i++) if(isCheck[sources[i]-1]) answer[i] = (val[sources[i]-1]);
    return answer;
}