#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 언어 [0 : cpp] [1 : java] [2 : python] / 직군 [0 : backend] [1 : frontend]
// 경력 [0 : junior] [1 : senior] / 소울푸드 [0 : chicken] [1 : pizza]
vector<vector<vector<vector<vector<int>>>>> db;

vector<int> solution(vector<string> info, vector<string> query) {

    vector<int> a1;
    vector<vector<int>> a2(2, a1);
    vector<vector<vector<int>>> a3(2, a2);
    vector<vector<vector<vector<int>>>> a4(2, a3);
    vector<vector<vector<vector<vector<int>>>>> a5(3, a4);
    db = a5;
    
    for(int i = 0; i < info.size(); i++)
    {
        string str = info[i]; int idx = 0;
        
        int c1, c2, c3, c4;
        
        if(str[idx] == 'c') { c1 = 0; idx += 4; }
        else if (str[idx] == 'j') { c1 = 1; idx += 5; }
        else if (str[idx] == 'p') { c1 = 2; idx += 7; }
        
        if(str[idx] == 'b') { c2 = 0; idx += 8; }
        else if(str[idx] == 'f') { c2 = 1; idx += 9; }
        
        if(str[idx] == 'j') { c3 = 0; idx += 7; }
        else if(str[idx] == 's') { c3 = 1; idx += 7; }
        
        if(str[idx] == 'c') { c4 = 0; idx += 8; }
        else if(str[idx] == 'p') { c4 = 1; idx += 6; }
        
        string valStr = "";
        for(; idx < str.size(); idx++) valStr += str[idx];
        
        int val = stoi(valStr);
        
        db[c1][c2][c3][c4].push_back(val);
    }
    
    for(int c1 = 0; c1 < 3; c1++)
        for(int c2 = 0; c2 < 2; c2++)
            for(int c3 = 0; c3 < 2; c3++)
                for(int c4 = 0; c4 < 2; c4++)
                    if(db[c1][c2][c3][c4].size() > 0)
                        sort(db[c1][c2][c3][c4].begin(), db[c1][c2][c3][c4].end());
    
    vector<int> answer;
    
    for(int q = 0; q < query.size(); q++)
    {
        string str = query[q]; int idx = 0;
        
        int k1, k2, k3, k4;
        
        if(str[idx] == 'c') { k1 = 0; idx += 8; }
        else if (str[idx] == 'j') { k1 = 1; idx += 9; }
        else if (str[idx] == 'p') { k1 = 2; idx += 11; }
        else { k1 = -1; idx += 6; }
        
        if(str[idx] == 'b') { k2 = 0; idx += 12; }
        else if(str[idx] == 'f') { k2 = 1; idx += 13; }
        else { k2 = -1; idx += 6; }
        
        if(str[idx] == 'j') { k3 = 0; idx += 11; }
        else if(str[idx] == 's') { k3 = 1; idx += 11; }
        else { k3 = -1; idx += 6; }
        
        if(str[idx] == 'c') { k4 = 0; idx += 8; }
        else if(str[idx] == 'p') { k4 = 1; idx += 6; }
        else { k4 = -1; idx += 2; }
        
        string valStr = "";
        for(; idx < str.size(); idx++) valStr += str[idx];
        
        int res = 0;
        int val = stoi(valStr);
        
        for(int c1 = 0; c1 < 3; c1++)
        { if(c1 != k1 && k1 != -1) continue;
            for(int c2 = 0; c2 < 2; c2++)
            { if(c2 != k2 && k2 != -1) continue;
                for(int c3 = 0; c3 < 2; c3++)
                { if(c3 != k3 && k3 != -1) continue;
                    for(int c4 = 0; c4 < 2; c4++)
                    { if(c4 != k4 && k4 != -1) continue;
                     
                     int sIdx = 0, eIdx = db[c1][c2][c3][c4].size();

                     while(sIdx < eIdx)
                     {
                        int mIdx = (sIdx + eIdx) / 2;
                        if(db[c1][c2][c3][c4][mIdx] >= val) eIdx = mIdx;
                        else sIdx = mIdx+1; 
                     }
                         
                     res += (db[c1][c2][c3][c4].size() - sIdx); 
                    }
                }
            }
        }
        
        answer.push_back(res);
    }
    
    return answer;
}