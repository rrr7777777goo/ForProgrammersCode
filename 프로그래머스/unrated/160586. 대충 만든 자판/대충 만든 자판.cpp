#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> ma;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int x = 0; x < keymap.size(); x++)
    {
        for(int i = 0; i < keymap[x].size(); i++)
        {
            if(ma[keymap[x][i]] == 0) ma[keymap[x][i]] = (i+1);
            else
            {
                if(i+1 < ma[keymap[x][i]]) ma[keymap[x][i]] = (i+1);
            }
        }
    }
    
    for(int t = 0; t < targets.size(); t++)
    {
        int sum = 0;
        for(int i = 0; i <= targets[t].size(); i++)
        {
            if(i == targets[t].size()) { answer.push_back(sum); break; }
            if(ma[targets[t][i]] == 0) { answer.push_back(-1); break; }
            sum += ma[targets[t][i]];
        }
    }
    
    return answer;
}