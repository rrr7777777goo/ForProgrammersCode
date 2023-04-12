#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

vector<vector<string>> vec;
int maxAtt;
map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>>> ma, resetMa;
typedef map<string, map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>>>::iterator iter1;
typedef map<string, map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>>::iterator iter2;
typedef map<string, map<string, map<string, map<string, map<string, map<string, int>>>>>>::iterator iter3;
typedef map<string, map<string, map<string, map<string, map<string, int>>>>>::iterator iter4;
typedef map<string, map<string, map<string, map<string, int>>>>::iterator iter5;
typedef map<string, map<string, map<string, int>>>::iterator iter6;
typedef map<string, map<string, int>>::iterator iter7;
typedef map<string, int>::iterator iter8;

vector<vector<int>> johab;

int answer = 0;

int count_True = 0, count_False = 0;
int limitTrue, limitFalse;
bool isUsed[8];

void DFS(int n)
{
    if(n == maxAtt)
    {
        vector<int> jh;
        for(int i = 0; i < vec.size(); i++)
        {
            vector<string> att(8, "---");
            for(int x = 0; x < maxAtt; x++)
            {
                if(isUsed[x]) { att[x] = vec[i][x]; jh.push_back(x); }
            }
            
            ma[att[0]][att[1]][att[2]][att[3]][att[4]][att[5]][att[6]][att[7]] += 1;
        }
        
        bool isCKey = true;
        for(iter1 it1 = ma.begin(); it1 != ma.end(); it1++)
        for(iter2 it2 = ma[it1->first].begin(); it2 != ma[it1->first].end(); it2++)
        for(iter3 it3 = ma[it1->first][it2->first].begin(); it3 != ma[it1->first][it2->first].end(); it3++)
        for(iter4 it4 = ma[it1->first][it2->first][it3->first].begin(); it4 != ma[it1->first][it2->first][it3->first].end(); it4++)
        for(iter5 it5 = ma[it1->first][it2->first][it3->first][it4->first].begin(); it5 != ma[it1->first][it2->first][it3->first][it4->first].end(); it5++)
        for(iter6 it6 = ma[it1->first][it2->first][it3->first][it4->first][it5->first].begin(); it6 != ma[it1->first][it2->first][it3->first][it4->first][it5->first].end(); it6++)
        for(iter7 it7 = ma[it1->first][it2->first][it3->first][it4->first][it5->first][it6->first].begin(); it7 != ma[it1->first][it2->first][it3->first][it4->first][it5->first][it6->first].end(); it7++)
        for(iter8 it8 = ma[it1->first][it2->first][it3->first][it4->first][it5->first][it6->first][it7->first].begin(); it8 != ma[it1->first][it2->first][it3->first][it4->first][it5->first][it6->first][it7->first].end(); it8++)
        {
            if(it8->second > 1) { isCKey = false; break; }
        }
        
        if(isCKey) 
        {
            bool isPlus = true;

            for(int x = 0; x < johab.size(); x++)
            {
                int cnt = 0, maxcnt = johab[x].size();
                for(int y = 0; y < johab[x].size(); y++) if(isUsed[johab[x][y]]) ++cnt;
                if(cnt == maxcnt) { isPlus = false; break; }
            }
            
            if(isPlus) { johab.push_back(jh); ++answer; }
        }
        
        ma = resetMa;
        return;
    }
    
    if(count_False < limitFalse) { ++count_False; isUsed[n] = false; DFS(n+1); --count_False; }
    if(count_True < limitTrue) { ++count_True; isUsed[n] = true; DFS(n+1); --count_True; }
    isUsed[n] = false;
}

int solution(vector<vector<string>> relation) {
    vec = relation;
    maxAtt = relation[0].size();
    
    limitTrue = 1; limitFalse = maxAtt - limitTrue;
    for(int i = 0; i < maxAtt; i++)
    {
        DFS(0);
        ++limitTrue; --limitFalse;
    }
    
    return answer;
}