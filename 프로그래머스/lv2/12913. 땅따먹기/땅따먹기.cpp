#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    for(int i = 1; i < land.size(); i++)
    {
        for(int y = 0; y < 4; y++)
        {
            int c1 = land[i-1][0] + land[i][y], c2 = land[i-1][1] + land[i][y],
                c3 = land[i-1][2] + land[i][y], c4 = land[i-1][3] + land[i][y];
            
            int maxi = land[i][y];
            if(y != 0 && maxi < c1) maxi = c1; if(y != 1 && maxi < c2) maxi = c2;
            if(y != 2 && maxi < c3) maxi = c3; if(y != 3 && maxi < c4) maxi = c4;
            land[i][y] = maxi;
        }
    }
    
    int answer = land[land.size()-1][3];
    
    int c1 = land[land.size()-1][0],
        c2 = land[land.size()-1][1],
        c3 = land[land.size()-1][2];
    
    if(answer < c1) answer = c1; if(answer < c2) answer = c2; if(answer < c3) answer = c3;
    
    return answer;
}