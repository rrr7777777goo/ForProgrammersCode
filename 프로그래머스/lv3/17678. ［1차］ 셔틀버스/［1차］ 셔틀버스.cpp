#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Time
{
    int hour, minute;
    Time(int h, int m) { hour = h; minute = m; }
    
    void plusTime(int v)
    {
        minute += v;
        if(minute >= 60) { minute -= 60; ++hour; }
    }
    void minusTimeOne()
    {
        --minute; if(minute < 0) { minute = 59; --hour; }
    }
    
    bool operator>(const Time &t) const
    {
        if(hour == t.hour) return minute > t.minute;
        else return hour > t.hour;
    }
};

string solution(int n, int t, int m, vector<string> timetable) {

    priority_queue<Time, vector<Time>, greater<Time>> qu;
    
    Time lastTime(9, 0);
    for(int i = 1; i < n; i++) lastTime.plusTime(t);
    
    for(int t = 0; t < timetable.size(); t++)
    {
        string str_hour = "", str_minute = "";
        str_hour += timetable[t][0]; str_hour += timetable[t][1];
        str_minute += timetable[t][3]; str_minute += timetable[t][4];
        int int_hour = stoi(str_hour), int_minute = stoi(str_minute);
        
        Time tmpTime(int_hour, int_minute);
        if(tmpTime > lastTime) { continue; } else { qu.push(tmpTime); }
    }
    
    Time currentTime(9, 0), answerTime(0, 0);
    
    while(true)
    {
        // cout << currentTime.hour << ":" << currentTime.minute << endl;
        int cnt = m; Time backupTime(0, 0);
        while(cnt > 0 && !qu.empty())
        {
            Time chkTime = qu.top(); backupTime = chkTime;
            if(chkTime > currentTime) break;
            else { qu.pop(); --cnt; }
        }
        
        --n;
        if(n == 0)
        {
            if(qu.empty())
            {
                if(cnt > 0) answerTime = currentTime;
                else { answerTime = backupTime; answerTime.minusTimeOne(); }
            }
            else { answerTime = backupTime; answerTime.minusTimeOne(); }
            break;
        }
        else { currentTime.plusTime(t); }
    }
    
    string answer = "", sh = "", sm = "";
    sh = to_string(answerTime.hour);
    if(sh.size() == 1) { string ttttt = "0"; ttttt += sh; sh = ttttt; }
    answer += sh;
    answer += ":";
    sm = to_string(answerTime.minute);
    if(sm.size() == 1) { string tttt = "0"; tttt += sm; sm = tttt; }
    answer += sm;
    return answer;
}