#include<vector>
#include<queue>
using namespace std;

// [세로][가로]
int sero, garo;
bool isBlock[101][101];

int solution(vector<vector<int>> maps)
{
    sero = maps.size(); garo = maps[0].size();
    for(int y = 0; y < maps.size(); y++)
    {
        for(int x = 0; x < maps[y].size(); x++)
        {
            isBlock[y+1][x+1] = maps[y][x];
        }
    }
    
    int count = 1;
    
    queue<int> qu_sero, qu_garo; qu_sero.push(1); qu_garo.push(1);
    
    bool isFinish = false;
    while(!qu_sero.empty())
    {
        ++count;
        queue<int> tqu_sero, tqu_garo;
        while(!qu_sero.empty())
        {
            int s = qu_sero.front(); qu_sero.pop();
            int g = qu_garo.front(); qu_garo.pop();
            
            if(s >= 2)
            {
                if(isBlock[s-1][g])
                {
                    if((s-1) == sero && g == garo) { isFinish = true; break; }
                    tqu_sero.push(s-1); tqu_garo.push(g);
                    isBlock[s-1][g] = false;
                }
            }
            if(s <= sero-1)
            {
                if(isBlock[s+1][g])
                {
                    if((s+1) == sero && g == garo) { isFinish = true; break; }
                    tqu_sero.push(s+1); tqu_garo.push(g);
                    isBlock[s+1][g] = false;                   
                }
            }
            if(g >= 2)
            {
                if(isBlock[s][g-1])
                {
                    if(s == sero && (g-1) == garo) { isFinish = true; break; }
                    tqu_sero.push(s); tqu_garo.push(g-1);
                    isBlock[s][g-1] = false;
                }
            }
            if(g <= garo-1)
            {
                if(isBlock[s][g+1])
                {
                    if(s == sero && (g+1) == garo) { isFinish = true; break; }
                    tqu_sero.push(s); tqu_garo.push(g+1);
                    isBlock[s][g+1] = false;
                }
            }
        }
        
        if(isFinish) break;
        qu_sero = tqu_sero; qu_garo = tqu_garo;
    }
    
    if(isFinish) return count;
    else return -1;
}