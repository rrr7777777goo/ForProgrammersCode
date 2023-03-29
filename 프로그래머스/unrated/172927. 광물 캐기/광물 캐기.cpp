#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Data
{
    vector<int> da;
    Data(vector<int> da) { this->da = da; }
    
    bool operator<(const Data & d) const
    {
        int tmp1 = 0, tmp2 = 0;
        for(int i = 0; i < 5; i++)
        {
            if(da[i] == 0) tmp1 += 25; else if(da[i] == 1) tmp1 += 5; else if(da[i] == 2) tmp1 += 1;
            
            if(d.da[i] == 0) tmp2 += 25; else if(d.da[i] == 1) tmp2 += 5; else if(d.da[i] == 2) tmp2 += 1;
        }
        
        return tmp1 < tmp2;
    }
};

int solution(vector<int> picks, vector<string> minerals) {
    
    if(minerals.size() % 5 > 0) 
    {
        int si = 5 - minerals.size() % 5;
        for(int i = 0; i < si; i++) minerals.push_back("blank");
    }
    
    priority_queue<Data> qu;
    
    int limit = picks[0] + picks[1] + picks[2], cnt = 0;
    for(int i = 0; i < minerals.size(); i += 5)
    {
        if(cnt == limit) break;
        
        vector<int> tmpVec;
        for(int x = 0; x < 5; x++)
        {
            if(minerals[i+x].compare("diamond") == 0) tmpVec.push_back(0);
            else if(minerals[i+x].compare("iron") == 0) tmpVec.push_back(1);
            else if(minerals[i+x].compare("stone") == 0) tmpVec.push_back(2);
            else if(minerals[i+x].compare("blank") == 0) tmpVec.push_back(3);
        }
        qu.push(Data(tmpVec));
        
        ++cnt;
    }
    
    int answer = 0;
    
    while(!qu.empty())
    {
        Data d = qu.top(); qu.pop();
        
        int item = -1; for(int i = 0; i <= 2; i++) { if(picks[i] > 0) { --picks[i]; item = i; break; } }
        
        int sum = 0;
        
        for(int i = 0; i < 5; i++)
        {
            switch(item)
            {
                case 0:
                    if(d.da[i] <= 2) ++sum;
                break;
                case 1:
                    if(d.da[i] == 0) sum += 5;
                    else if(d.da[i] <= 2) ++sum;
                break;
                case 2:
                    if(d.da[i] == 0) sum += 25;
                    else if(d.da[i] == 1) sum += 5;
                    else if(d.da[i] <= 2) ++sum;
                break;
            }
        }
        
        answer += sum;
    }
    
    return answer;
}