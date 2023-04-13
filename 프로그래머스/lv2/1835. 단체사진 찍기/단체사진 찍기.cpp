#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int answer;
int findIdx[26];
vector<string> cas;
vector<char> fr; vector<bool> isUsed;

vector<char> photo;
void DFS(int nu)
{
    if(nu == 8)
    {
        bool isCorrect = true;
        for(int i = 0; i < cas.size(); i++)
        {
            int i1 = findIdx[cas[i][0] - 'A'], i2 = findIdx[cas[i][2] - 'A'], i3 = cas[i][4] - '0' + 1;

            if(cas[i][3] == '<')
            {
                if(abs(i1 - i2) < i3) continue;
                else { isCorrect = false; break; }
            }
            else if (cas[i][3] == '=')
            {
                if(abs(i1 - i2) == i3) continue;
                else { isCorrect = false; break; }
            }
            else
            {
                if(abs(i1 - i2) > i3) continue;
                else { isCorrect = false; break; }
            }
        }

        if(isCorrect) ++answer;
        return;
    }

    for(int i = 0; i < 8; i++)
    {
        if(!isUsed[i])
        {
            isUsed[i] = true;
            photo.push_back(fr[i]);
            findIdx[fr[i]-'A'] = photo.size() - 1;
            DFS(nu + 1);
            findIdx[fr[i]-'A'] = 0;
            photo.pop_back();
            isUsed[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;

    cas = data;

    for(int i = 0; i < 26; i++) findIdx[i] = 0;

    fr.push_back('A'); fr.push_back('C'); fr.push_back('F'); fr.push_back('J');
    fr.push_back('M'); fr.push_back('N'); fr.push_back('R'); fr.push_back('T');
    isUsed = vector<bool>(8, false);

    DFS(0);

    return answer;
}