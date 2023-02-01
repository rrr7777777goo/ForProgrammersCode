#include <string>
#include <vector>
using namespace std;

int score[26];

string solution(vector<string> survey, vector<int> choices) {
    for(int i = 0; i < survey.size(); i++)
    {
        switch(choices[i])
        {
            case 1:
                score[survey[i][0] - 'A'] += 3;
                break;
            case 2:
                score[survey[i][0] - 'A'] += 2;
                break;
            case 3:
                score[survey[i][0] - 'A'] += 1;
                break;
            case 4:
                break;
            case 5:
                score[survey[i][1] - 'A'] += 1;
                break;
            case 6:
                score[survey[i][1] - 'A'] += 2;
                break;
            case 7:
                score[survey[i][1] - 'A'] += 3;
                break;
        }
    }
    
    string answer = "";
    if(score['R' - 'A'] >= score['T' - 'A']) answer += 'R'; else answer += 'T';
    if(score['C' - 'A'] >= score['F' - 'A']) answer += 'C'; else answer += 'F';
    if(score['J' - 'A'] >= score['M' - 'A']) answer += 'J'; else answer += 'M';
    if(score['A' - 'A'] >= score['N' - 'A']) answer += 'A'; else answer += 'N';
    return answer;
}