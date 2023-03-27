#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2, 0);
    
    for(int y = 0; y < park.size(); y++) for(int x = 0; x < park[y].size(); x++) if(park[y][x] == 'S') { answer[0] = y; answer[1] = x; break; }
    
    for(int i = 0; i < routes.size(); i++)
    {
        // cout << answer[0] << " " << answer[1] << endl;
        
        bool isWrong = false; int val = routes[i][2] - '0';
        if(routes[i][0] == 'E')
        {
            if(answer[1] + val >= park[0].size()) continue;
            
            for(int x = answer[1] + 1; x <= answer[1] + val; x++) if(park[answer[0]][x] == 'X') { isWrong = true; break; }
            if(!isWrong) answer[1] += val;
        }
        else if(routes[i][0] == 'W')
        {
            if(answer[1] - val < 0) continue;
            
            for(int x = answer[1] - 1; x >= answer[1] - val; x--) if(park[answer[0]][x] == 'X') { isWrong = true; break; }
            if(!isWrong) answer[1] -= val;
        }
        else if(routes[i][0] == 'S')
        {
            if(answer[0] + val >= park.size()) continue;
            
            for(int y = answer[0] + 1; y <= answer[0] + val; y++) if(park[y][answer[1]] == 'X') { isWrong = true; break; }
            if(!isWrong) answer[0] += val;
        }
        else if(routes[i][0] == 'N')
        {
            if(answer[0] - val < 0) continue;
            
            for(int y = answer[0] - 1; y >= answer[0] - val; y--) if(park[y][answer[1]] == 'X') { isWrong = true; break; }
            if(!isWrong) answer[0] -= val;
        }
    }
    
    // cout << answer[0] << " " << answer[1] << endl;
    
    return answer;
}