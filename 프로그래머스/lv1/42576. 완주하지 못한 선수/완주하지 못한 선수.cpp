#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> map_C;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i = 0; i < completion.size(); i++) { map_C[completion[i]] += 1; }
    
    for(int i = 0; i < participant.size(); i++)
    {
        if(map_C[participant[i]] >= 1) map_C[participant[i]] -= 1;
        else { answer = participant[i]; break; }
    }
    
    return answer;
}

/*
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end()); sort(completion.begin(), completion.end());
    
    completion.push_back("_F_I_N_I_S_H_");
    
    for(int i = 0; i < participant.size(); i++)
    {
        if(participant[i].compare(completion[i]) != 0)
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}
*/