#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Time
{
    int hour, minute;
    Time() {}
    Time(int h, int m) { hour = h; minute = m; }
    
    bool operator==(const Time &t) const { return (hour == t.hour) && (minute == t.minute); }
    
    bool operator>(const Time &t) const
    {
        if(hour == t.hour) return minute > t.minute;
        else return hour > t.hour;
    }
    
    bool operator<(const Time &t) const
    {
        if(hour == t.hour) return minute < t.minute;
        else return hour < t.hour;
    }
};

struct Book
{
    Time startTime, endTime;
    
    bool operator<(const Book &b) const
    {
        if(startTime == b.startTime) return b.endTime < endTime;
        else return b.startTime < startTime;
    }
};

int cnt = -1;
vector<Book> vec_Book[1000];
priority_queue<Book> qu;
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int c = 0; c < book_time.size(); c++)
    {
        int sh = stoi(book_time[c][0].substr(0, 2)), sm = stoi(book_time[c][0].substr(3, 2)),
            eh = stoi(book_time[c][1].substr(0, 2)), em = stoi(book_time[c][1].substr(3, 2)); em += 9;
        if(em >= 60) { em -= 60; eh += 1; if(eh == 24) { eh = 23; em = 59; } }
        
        Book tb;
        tb.startTime = Time(sh, sm); tb.endTime = Time(eh, em);
        qu.push(tb);
    }
    
    while(!qu.empty())
    {
        Book b = qu.top(); qu.pop();
        
        int len = cnt+1;
        for(int i = 0; i <= len; i++)
        {
            if(i == len)
            {
                ++cnt;
                vec_Book[i].push_back(b);
            }
            else
            {
                if(b.startTime > vec_Book[i][vec_Book[i].size() - 1].endTime)
                {
                    vec_Book[i].push_back(b);
                    break;
                }
            }
        }
    }

    return cnt+1;
}