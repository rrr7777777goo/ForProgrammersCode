#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> ma;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    
    int mini = 101, maxi = -101;
    for(int i = 0; i < lines.size(); i++)
    {
        int left = lines[i][0], right = lines[i][1] - 1;
        if(left < mini) mini = left; if(right > maxi) maxi = right;
        
        for(int x = left; x <= right; x++) ++ma[x];
    }
    
    for(int i = mini; i <= maxi; i++)
    {
        if(ma[i] > 1) ++answer;
    }
    
    return answer;
}