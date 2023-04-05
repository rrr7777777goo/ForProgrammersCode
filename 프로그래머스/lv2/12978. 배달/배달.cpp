#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    
    vector<vector<int>> graph; vector<int> tV(N+1, 1000000);
    for(int i = 0; i <= N; i++) { graph.push_back(tV); graph[i][i] = 0; }
    
    vector<bool> isCheck(N+1, false);
    for(int i = 0; i < road.size(); i++)
    {
        int x = road[i][0], y = road[i][1], val = road[i][2];
        if(graph[x][y] > val) { graph[x][y] = val; graph[y][x] = val; }
    }
    
    vector<int> vec_time(N+1, 1000000);
    for(int i = 1; i <= N; i++) vec_time[i] = graph[1][i];
    
    int currentIdx = 1; isCheck[currentIdx] = true;
    
    while(true)
    {
        int nextIdx = -1, mini = 1000000;
        
        for(int i = 1; i <= N; i++)
        {
            if(isCheck[i]) continue;
            
            if(graph[currentIdx][i] < 10001)
            {
                int c1 = vec_time[currentIdx] + graph[currentIdx][i];
                int c2 = vec_time[i];
                vec_time[i] = c1 < c2 ? c1 : c2;
            }
            
            if(vec_time[i] < mini) { nextIdx = i; mini = vec_time[i]; }
        }
        
        if(nextIdx == -1) break;
        
        currentIdx = nextIdx; isCheck[currentIdx] = true;
    }
    
    int answer = 0;
    for(int i = 1; i <= N; i++) if(vec_time[i] <= K) ++answer;
    return answer;
}