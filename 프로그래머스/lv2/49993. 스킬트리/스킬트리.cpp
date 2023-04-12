#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, bool> isLearn, resetLearn;
map<char, char> isPrev;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 1; i < skill.size(); i++) isPrev[skill[i]] = skill[i-1];
    
    for(int t = 0; t < skill_trees.size(); t++)
    {
        isLearn = resetLearn;
        
        string tstr = skill_trees[t];
        
        bool isCorrect = true;
        for(int i = 0; i < tstr.size(); i++)
        {
            char c = tstr[i];
            if(isPrev[c] > 0 && isLearn[isPrev[c]] == false) { isCorrect = false; break; }
            else isLearn[c] = true;
        }
        if(isCorrect) ++answer;
    }
    
    return answer;
}