#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Data
{
    // sum : 돈 합 / plus : 가입자 수
    int sum, plus;
    Data(int s, int p) { sum = s; plus = p; }
    
    bool operator<(const Data &d) const
    {
        if(plus == d.plus) return sum < d.sum;
        else return plus < d.plus;
    }
};

priority_queue<Data> qu;

vector<vector<int>> us;
vector<int> emo, hal;

int zxc = 0;
void DFS(int c)
{
    if(c == emo.size())
    {
        int sum = 0, plus = 0;  // sum : 돈합 / plus : 가입자 수
        
        for(int i = 0; i < us.size(); i++)
        {
            int tmp = 0;
            
            for(int e = 0; e < emo.size(); e++) if(hal[e] >= us[i][0]) tmp += emo[e];
            
            if(tmp >= us[i][1]) ++plus;
            else sum += tmp;
        }
        
        qu.push(Data(sum, plus));
        
        return;
    }
    
    int per = 50;
    for(int i = 0; i < 4; i++)
    {
        per += 10; hal[c] -= 10;
        int previous_Emo = emo[c];
        emo[c] /= 100; emo[c] *= per;
        DFS(c+1);
        emo[c] = previous_Emo;
    }
    hal[c] = 50;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    us = users;
    emo = emoticons;
    hal = vector<int>(emo.size(), 50);
    
    DFS(0);
    
    answer.push_back(qu.top().plus); answer.push_back(qu.top().sum);
    
    return answer;
}