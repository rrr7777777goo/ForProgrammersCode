#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Time
{
    int hour, minute;
    Time(int h, int m) { hour = h; minute = m; }
    
    void PlusTime()
    {
        ++minute;
        if(minute == 60) { minute = 0; ++hour; if(hour == 24) hour = 0; }
    }
    
    bool operator>=(const Time & tt) const
    {
        if(hour > tt.hour) return true;
        else if((hour == tt.hour) && (minute >= tt.minute)) return true;
        else return false;
    }
};

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    string mem = "";
    
    for(int i = 0; i < m.size(); i++)
    {
        if(i+1 < m.size())
        {
            if(m[i+1] == '#') { mem += (m[i] + 7); i++; }
            else mem += m[i];
        }
        else mem += m[i];
    }
    
    int maxiLen = -1;
    for(int i = 0; i < musicinfos.size(); i++)
    {
        string startHour = ""; startHour += musicinfos[i][0]; startHour += musicinfos[i][1];
        string startMin = ""; startMin += musicinfos[i][3]; startMin += musicinfos[i][4];
        string endHour = ""; endHour += musicinfos[i][6]; endHour += musicinfos[i][7];
        string endMin = ""; endMin += musicinfos[i][9]; endMin += musicinfos[i][10];
        
        int sH = stoi(startHour), sM = stoi(startMin), eH = stoi(endHour), eM = stoi(endMin);
        
        int n = 12; string musicName = "", musicMelody = "";
        while(musicinfos[i][n] != ',') { musicName += musicinfos[i][n++]; }
        ++n;
        while(n < musicinfos[i].size()) { musicMelody += musicinfos[i][n++]; }
        
        Time sHour(sH, sM), eHour(eH, eM);
        
        string mel = "";
        
        int x = 0, musicLength = 0;
        
        
        while (true)
        {
            if(sHour >= eHour) break;
            
            if(x+1 < musicMelody.size())
            {
                if(musicMelody[x+1] == '#') { mel += (musicMelody[x] + 7); x += 1; }
                else mel += musicMelody[x];
            }
            else mel += musicMelody[x];
            
            sHour.PlusTime(); ++musicLength;

            x += 1; 
            if(x == musicMelody.size()) x = 0;
        }
        
        if(mel.find(mem) != -1)
        {
            if(musicLength > maxiLen)
            {
                maxiLen = musicLength;
                answer = musicName;
            }
        }
    }
    
    
    return answer;
}