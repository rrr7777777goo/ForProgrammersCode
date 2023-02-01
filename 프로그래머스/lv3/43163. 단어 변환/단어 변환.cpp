#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    map<string, bool> isAlreadyCheck;
    int answer = 0;
    bool isFind = false;
    
    queue<string> qu; qu.push(begin);
    int len = words[0].size();
    
    queue<string> tmp_qu, reset_qu;
    ++answer;
    
    while(true)
    {
        string currentStr = qu.front(); qu.pop();
        for(int w = 0; w < words.size(); w++)
        {
            if(isAlreadyCheck[words[w]]) continue;
            
            bool isChangeable = true, onlyOne = false;
            for(int t = 0; t < len; t++)
            {
                if(words[w][t] != currentStr[t])
                {
                    if(!onlyOne) onlyOne = true;
                    else { isChangeable = false; break; }
                }
            }
            if(isChangeable) 
            {
                if(words[w].compare(target) == 0)
                {
                    isFind = true;
                    break;
                }
                else
                {
                    tmp_qu.push(words[w]);
                    isAlreadyCheck[words[w]] = true;                    
                }
            }
        }
        
        if(isFind) break;
        
        if(qu.empty())
        {
            ++answer;
            if(!tmp_qu.empty()) { qu = tmp_qu; tmp_qu = reset_qu; }
            else break;
        }
    }
    
    if(!isFind) return 0;
    else return answer;
}