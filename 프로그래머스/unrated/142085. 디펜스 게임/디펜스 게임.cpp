#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    
    priority_queue<int, vector<int>, greater<int>> qu;
    
    int answer = 0;

    for(int z = 0; z < enemy.size(); z++)
    {
        if(k > 0) { qu.push(enemy[z]); --k; }
        else
        {
            int t = qu.top(); qu.pop();
            int mini = t < enemy[z] ? t : enemy[z], maxi = t > enemy[z] ? t : enemy[z];
            qu.push(maxi);
            if(n - mini < 0) break;
            else n -= mini;
        }
        
       ++answer;
    }
    
    return answer;
}