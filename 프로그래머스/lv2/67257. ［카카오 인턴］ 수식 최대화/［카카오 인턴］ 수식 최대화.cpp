#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

map<vector<char>, bool> ma;

long long solution(string expression) {
    long long answer = 0;

    int cnt_Plus = 0, cnt_Minus = 0, cnt_Mul = 0;
    
    int x = 0; while(true) { x = expression.find('+', x); if(x == -1) break; else { ++cnt_Plus; ++x; } }
    x = 0; while(true) { x = expression.find('-', x); if(x == -1) break; else { expression[x] = '_'; ++cnt_Minus; ++x; } }
    x = 0; while(true) { x = expression.find('*', x); if(x == -1) break; else { ++cnt_Mul; ++x; } }
    
    vector<vector<char>> sS; for(int i = 0; i < 6; i++) sS.push_back(vector<char>());
    
    if(cnt_Plus > 0) sS[0].push_back('+'); if(cnt_Minus > 0) sS[0].push_back('_'); if(cnt_Mul > 0) sS[0].push_back('*');
    if(cnt_Minus > 0) sS[1].push_back('_'); if(cnt_Plus > 0)sS[1].push_back('+'); if(cnt_Mul > 0) sS[1].push_back('*');
    if(cnt_Mul > 0) sS[2].push_back('*'); if(cnt_Minus > 0) sS[2].push_back('_'); if(cnt_Plus > 0) sS[2].push_back('+');
    if(cnt_Minus > 0) sS[3].push_back('_'); if(cnt_Mul > 0) sS[3].push_back('*'); if(cnt_Plus > 0) sS[3].push_back('+');
    if(cnt_Mul > 0) sS[4].push_back('*'); if(cnt_Plus > 0) sS[4].push_back('+'); if(cnt_Minus > 0) sS[4].push_back('_');
    if(cnt_Plus > 0) sS[5].push_back('+'); if(cnt_Mul > 0) sS[5].push_back('*'); if(cnt_Minus > 0) sS[5].push_back('_');
    
    for(int ca = 0; ca < sS.size(); ca++)
    {
        if(ma[sS[ca]] == true) continue; ma[sS[ca]] = true;
        
        string backupStr = expression;

        for(int y = 0; y < sS[ca].size(); y++)
        {
            char buho = sS[ca][y];
            
            while(true)
            {
                int idx_buho = expression.find(buho, 0);
            
                if(idx_buho == -1) break;
                
                int finalLeft = 0, finalRight = expression.size();

                string lStr = "";
                for(int i = idx_buho - 1; i >= 0; i--)
                {
                    if(expression[i] >= '0' && expression[i] <= '9' || expression[i] == '-')
                    {
                        string tStr = ""; tStr += expression[i];
                        lStr = tStr + lStr;
                    }
                    else { finalLeft = i+1; break; }
                }
                
                string rStr = "";
                for(int i = idx_buho + 1; i < expression.size(); i++)
                {
                    if(expression[i] >= '0' && expression[i] <= '9' || expression[i] == '-')
                    {
                        string tStr = ""; tStr += expression[i];
                        rStr = rStr + tStr;
                    }
                    else { finalRight = i; break; }
                }
            
                long long lII = stoll(lStr), rII = stoll(rStr), sum = 0;
                if(buho == '+') sum = lII + rII;
                else if (buho == '_') sum = lII - rII;
                else sum = lII * rII;
                
                string cStr = to_string(sum);
                lStr = expression.substr(0, finalLeft);
                rStr = expression.substr(finalRight, -1);
                expression = lStr; expression += cStr; expression += rStr;
            }
        }
        long long tempValue = stoll(expression);
        tempValue = abs(tempValue);
        if(answer < tempValue) answer = tempValue;
        
        expression = backupStr;
    }
    
    return answer;
}