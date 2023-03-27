#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(int q = 0; q < quiz.size(); q++)
    {
        int cnt = 0; char buho = ' '; string x = "", y = "", z = "";
        for(int i = 0; i < quiz[q].size(); i++)
        {
            if(quiz[q][i] == ' ') ++cnt;
            else
            {
                if(cnt == 0) x += quiz[q][i];
                else if (cnt == 1) buho = quiz[q][i];
                else if (cnt == 2) y += quiz[q][i];
                else if (cnt == 4) z += quiz[q][i];
            }
        }
        if(buho == '+')
        {
            if(stoi(x) + stoi(y) == stoi(z)) answer.push_back("O");
            else answer.push_back("X");
        }
        else
        {
            if(stoi(x) - stoi(y) == stoi(z)) answer.push_back("O");
            else answer.push_back("X");
        }
    }
    
    return answer;
}