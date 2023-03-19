#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4, 51); answer[2] = 0; answer[3] = 0;
    
    for(int y = 0; y < wallpaper.size(); y++)
    {
        for(int x = 0; x < wallpaper[y].size(); x++)
        {
            if(wallpaper[y][x] == '#')
            {
                if(y < answer[0]) answer[0] = y;
                if(x < answer[1]) answer[1] = x;
                if(y+1 > answer[2]) answer[2] = y+1;
                if(x+1 > answer[3]) answer[3] = x+1;
            }
        }
    }
    
    return answer;
}