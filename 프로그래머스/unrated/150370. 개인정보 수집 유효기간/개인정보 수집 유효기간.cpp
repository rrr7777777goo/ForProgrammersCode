#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<char, int> ter;

struct Date
{
    int year, month, day;
    
    Date(int y, int m, int d) { year = y; month = m; day = d; }
    
    void plusMonth(int x)
    {
        month += x;
        
        while(month > 12)
        {
            month -= 12;
            ++year;
        }
        
        day -= 1;
        if(day <= 0)
        {
            month -= 1;
            day += 28;
            if(month <= 0)
            {
                year -= 1;
                month += 12;
            }
        }
    }
    
    bool operator<(const Date &da) const
    {
        if(year == da.year)
        {
            if(month == da.month)
            {
                return day < da.day;
            }
            else return month < da.month;
        }
        else return year < da.year;
    }
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int t = 0; t < terms.size(); t++)
    {
        char c = terms[t][0];
        
        string str = "";
        for(int i = 2; i < terms[t].size(); i++)
        {
            str += terms[t][i];
        }
        int istr = stoi(str);
        ter[c] = istr;
    }
    
    string yo = ""; yo += today[0]; yo += today[1]; yo += today[2]; yo += today[3];
    string mo = ""; mo += today[5]; mo += today[6];
    string doo = ""; doo += today[8]; doo += today[9];
    int iyo = stoi(yo), imo = stoi(mo), idoo = stoi(doo);
    
    Date cD(iyo, imo, idoo);
    
    for(int v = 0; v < privacies.size(); v++)
    {
        string tyo = ""; tyo += privacies[v][0]; tyo += privacies[v][1]; tyo += privacies[v][2]; tyo += privacies[v][3];
        string tmo = ""; tmo += privacies[v][5]; tmo += privacies[v][6];
        string tdoo = ""; tdoo += privacies[v][8]; tdoo += privacies[v][9];
        int ityo = stoi(tyo), itmo = stoi(tmo), itdoo = stoi(tdoo);
        char tC = privacies[v][11];
        
        Date tD(ityo, itmo, itdoo);
        tD.plusMonth(ter[tC]);
        
        if(tD < cD) { answer.push_back(v+1); }
    }
    
    return answer;
}