#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, bool> spe, ma, rst;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    
    for(int i = 0; i < spell.size(); i++) { spe[spell[i][0]] = true; }

    int mX = spe.size();
    for(int i = 0; i < dic.size(); i++)
    {
        for(int s = 0; s < dic[i].size(); s++)
        {
            if(spe[dic[i][s]]) { ma[dic[i][s]] = true; }
        }
        
        if(mX == ma.size()) { answer = 1; break; }
        ma = rst;
    }
    
    return answer;
}