#include <string>
#include <vector>
#include <iostream>
using namespace std;

char la[17];

int jin;
string strN = "0";

void PlusPlus()
{
    int i = strN.size() - 1;
    while(true)
    {
        if(i == -1)
        {
            string newStr = "1";
            newStr += strN; strN = newStr;
            break;
        }
        
        if(strN[i] == '9') strN[i] = 'A'; else ++strN[i]; // 1 증가
        
        if(strN[i] == la[jin]) { strN[i] = '0'; --i; }
        else break;
    }
}

string solution(int n, int t, int m, int p) {
    for(int i = 2; i <= 16; i++)
    {
        if(i >= 10) { la[i] = (i-10) + 'A'; }
        else { la[i] = i + '0'; }
    }
    
    jin = n; p -= 1;
    
    string answer = ""; int cnt = 0;
    
    for(int num = 0; ; num++)
    {
        if(num > 0) PlusPlus();
        
        string checkStr = strN;
        
        for(int i = 0; i < checkStr.size(); i++)
        {
            char c = checkStr[i];
            if(cnt == p) { answer += c; if(answer.size() == t) break; }
            cnt = (cnt + 1) % m;
        }
        
        if(answer.size() == t) break;
    }
    
    return answer;
}