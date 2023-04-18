#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Time
{
    int s_day, s_hour, s_minute, s_second, s_milisecond,
        e_day, e_hour, e_minute, e_second, e_milisecond;
    
    Time() {}
    Time(int d, int h, int mi, int s, int ms, int ch_s, int ch_ms)
    {
        e_day = d; s_day = d;
        e_hour = h; s_hour = h;
        e_minute = mi; s_minute = mi;
        e_second = s; s_second = s;
        e_milisecond = ms; s_milisecond = ms;
        
        e_milisecond += 999;
        if(e_milisecond > 999) { ++e_second; e_milisecond -= 1000; }
        if(e_second > 59) { ++e_minute; e_second -= 60; } 
        if(e_minute > 59) { ++e_hour; e_minute -= 60; }
        if(e_hour > 23) { ++e_day; e_hour -= 24; }
        
        --ch_ms; if(ch_ms < 0) { --ch_s; ch_ms += 1000; }
        
        s_milisecond -= ch_ms; s_second -= ch_s;
        if(s_milisecond < 0) { --s_second; s_milisecond += 1000; }
        if(s_second < 0) { --s_minute; s_second += 60; }
        if(s_minute < 0) { --s_hour; s_minute += 60; }
        if(s_hour < 0) { --s_day; s_hour += 24; }
    }
    
    bool operator<(const Time &t) const
    {
        if(e_day == t.s_day)
        {
            if(e_hour == t.s_hour)
            {
                if(e_minute == t.s_minute)
                {
                    if(e_second == t.s_second)
                    {
                        return e_milisecond < t.s_milisecond;
                    } else return e_second < t.s_second;
                } else return e_minute < t.s_minute;
            } else return e_hour < t.s_hour;
        } else return e_day < t.s_day;
    }
    
    bool operator>(const Time &t) const
    {
        if(s_day == t.s_day)
        {
            if(s_hour == t.s_hour)
            {
                if(s_minute == t.s_minute)
                {
                    if(s_second == t.s_second) 
                    {
                        if(s_milisecond == t.s_milisecond)
                        {
                            if(e_day == t.e_day)
                            {
                            if(e_hour == t.e_hour)
                            {
                            if(e_minute == t.e_minute)
                            {
                            if(e_second == t.e_second)
                            {
                                return e_milisecond > t.e_milisecond;
                            } else return e_second > t.e_second;
                            } else return e_minute > t.e_minute;
                            } else return e_hour > t.e_hour;
                            } else return e_day > t.e_day;
                        }
                        return s_milisecond > t.s_milisecond;
                    }
                    else return s_second > t.s_second;
                }
                else return s_minute > t.s_minute;
            }
            else return s_hour > t.s_hour;
        }
        else return s_day > t.s_day;
    }
};

Time lastTime[2000];

priority_queue<Time, vector<Time>, greater<Time>> qu;
int solution(vector<string> lines) {
    int Idx = 0;
    
    for(int ca = 0; ca < lines.size(); ca++)
    {
        string sday = ""; sday += lines[ca][8]; sday += lines[ca][9];
        string shour = ""; shour += lines[ca][11]; shour += lines[ca][12];
        string smin = ""; smin += lines[ca][14]; smin += lines[ca][15];
        string ss = ""; ss += lines[ca][17]; ss += lines[ca][18];
        string sms = ""; sms += lines[ca][20]; sms += lines[ca][21]; sms += lines[ca][22];
        
        string scs = "", scms = ""; bool isCheckFirst = true;
        for(int i = 24; i < lines[ca].size()-1; i++)
        {
            if(lines[ca][i] == '.') { isCheckFirst = false; continue; }
            if(isCheckFirst) scs += lines[ca][i]; else scms += lines[ca][i];
        } if(scms.compare("") == 0) scms = "0";
        
        int day = stoi(sday), hour = stoi(shour), min = stoi(smin),
        s = stoi(ss), ms = stoi(sms), cs = stoi(scs), cms = stoi(scms);
        qu.push(Time(day, hour, min, s, ms, cs, cms));
    }
    
    while(!qu.empty())
    {
        Time nowTime = qu.top(); qu.pop();
        
        for(int i = 0; i <= Idx; i++)
        {
            if(i == Idx) { lastTime[Idx++] = nowTime; break; }
            else { if(lastTime[i] < nowTime) { lastTime[i] = nowTime; break; } }
        }
    }
    
    return Idx;
}