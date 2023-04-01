#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct Homework {
    string name;
    int minute, second;
    int count;
    
    Homework(string n, int m, int s, int c) { name = n; minute = m; second = s; count = c; }
    
    bool operator<(const Homework & h) const
    {
        if(minute == h.minute) return second > h.second;
        else return minute > h.minute;
    }
    
    void nextTime()
    {
        --count;
        ++second; if(second == 60) { ++minute; second = 0; }
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    priority_queue<Homework> qu;
    
    for(int i = 0; i < plans.size(); i++)
    {
        string mi = "", se = "", t = "";
        for(int x = 0; x < plans[i][1].size(); x++)
        {
            if(plans[i][1][x] == ':') { mi = t; t = ""; }
            else t += plans[i][1][x];
        }
        se = t;
        qu.push(Homework(plans[i][0], stoi(mi), stoi(se), stoi(plans[i][2])));
    }
    
    Homework currentHomework = qu.top(); qu.pop();
    
    stack<Homework> stac;
    
    while(true)
    {
        if(qu.empty()) { answer.push_back(currentHomework.name); break; }
        else
        {
            currentHomework.nextTime();

            if(currentHomework.count == 0) 
            {
                answer.push_back(currentHomework.name);

                if(currentHomework.minute == qu.top().minute
                   && currentHomework.second == qu.top().second)
                {
                    currentHomework = qu.top(); qu.pop();
                }
                else if(!stac.empty())
                {
                    int tMinute = currentHomework.minute, tSecond = currentHomework.second;
                    currentHomework = stac.top(); stac.pop();
                    currentHomework.minute = tMinute; currentHomework.second = tSecond;
                }
                else
                {
                    currentHomework = qu.top(); qu.pop();
                }
            }
            else
            {
                if(currentHomework.minute == qu.top().minute
                   && currentHomework.second == qu.top().second)
                {
                    stac.push(currentHomework);
                    currentHomework = qu.top(); qu.pop();
                }
            }
        }
    }
    
    while(!stac.empty())
    {
        answer.push_back(stac.top().name); stac.pop();
    }
    
    return answer;
}