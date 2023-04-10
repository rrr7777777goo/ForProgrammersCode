#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

bool isCourse[11];
int maxi[11];
vector<string> list[11], resetVec;

map<string, bool> jh;
map<string, bool> johab[20];
typedef map<string, bool>::iterator iter;

priority_queue<string, vector<string>, greater<string>> qu;

int maxC;
int dnum; string dstr;

string tmp = "";
void DFS(int n)
{
    if(isCourse[tmp.size()])
    {
        johab[dnum][tmp] = true;
        jh[tmp] = true;
    }
    
    if(tmp.size() < maxC)
    {
       for(int i = n; i < dstr.size(); i++)
       {
           string backuptmp = tmp; tmp += dstr[i];
           DFS(i+1);
           tmp = backuptmp;
       }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(int i = 0; i < course.size(); i++) isCourse[course[i]] = true;
    
    maxC = course[course.size() - 1];
    for(int i = 0; i < orders.size(); i++)
    {
        dnum = i; dstr = orders[i]; sort(dstr.begin(), dstr.end());
        DFS(0);
    }
    
    for(iter it = jh.begin(); it != jh.end(); it++)
    {
        string chk = it->first;
        int len = it->first.size(), cnt = 0;
        
        for(int i = 0; i < orders.size(); i++)
        {
            if(johab[i][chk] == true) ++cnt;
        }
        
        if(cnt >= 2)
        {
            if(maxi[len] < cnt)
            {
                maxi[len] = cnt;
                list[len] = resetVec; list[len].push_back(chk);
            }
            else if(maxi[len] == cnt) { list[len].push_back(chk); }
        }
    }
    
    for(int i = 0; i < course.size(); i++)
    {
        int n = course[i];
        
        for(int x = 0; x < list[n].size(); x++)
        {
            qu.push(list[n][x]);
        }
    }
    
    vector<string> answer;
    
    while(!qu.empty())
    {
        answer.push_back(qu.top());
        qu.pop();
    }
    
    return answer;
}