#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

int answer;
vector<char> fri;
map<char, int> ma;
vector<string> dda;

int z2 = 0;
void DFS(int n)
{
    if(n == 8)
    {
        bool isCorrect = true;
        
        for(int i = 0; i < dda.size(); i++)
        {
            int len = abs(ma[dda[i][0]] - ma[dda[i][2]]);
            int gan = dda[i][4] - '0' + 1;
            switch(dda[i][3])
            {
                case '<': if(len >= gan) isCorrect = false; break;
                case '=': if(len != gan) isCorrect = false; break;
                case '>': if(len <= gan) isCorrect = false; break;
            }
            if(!isCorrect) break;
        }
        
        if(isCorrect) ++answer;
        return;
    }
    
    for(int i = 0; i < fri.size(); i++)
    {
        if(ma[fri[i]] == 0)
        {
            ma[fri[i]] = (n+1);
            DFS(n+1);
            ma[fri[i]] = 0;
        }
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    
    dda = data;
    
    fri = vector<char>();
    fri.push_back('A'); fri.push_back('C'); fri.push_back('F'); fri.push_back('J');
    fri.push_back('M'); fri.push_back('N'); fri.push_back('R'); fri.push_back('T');
    
    ma = map<char, int>();
    for(int i = 0; i < fri.size(); i++) ma[fri[i]] = 0;
    
    DFS(0);
    
    return answer;
}