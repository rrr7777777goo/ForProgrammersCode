#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int cC, modSum[2500];

struct Data
{
    vector<int> v;
    Data(vector<int> v) { this->v = v; }
    
    bool operator>(const Data &d) const
    {
        if(v[cC] == d.v[cC]) return v[0] < d.v[0];
        else return v[cC] > d.v[cC];
    }
};

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    cC = col - 1; --row_begin; --row_end;
    
    priority_queue<Data, vector<Data>, greater<Data>> qu;
    
    for(int i = 0; i < data.size(); i++) qu.push(Data(data[i]));
    
    vector<Data> vec; while(!qu.empty()) { vec.push_back(qu.top()); qu.pop(); }
    
    int answer = 0;
    
    for(int a = row_begin; a <= row_end; a++)
    {
        for(int i = 0; i < vec[a].v.size(); i++) modSum[a] += vec[a].v[i] % (a+1);
        answer ^= modSum[a];
    }
    
    return answer;
}