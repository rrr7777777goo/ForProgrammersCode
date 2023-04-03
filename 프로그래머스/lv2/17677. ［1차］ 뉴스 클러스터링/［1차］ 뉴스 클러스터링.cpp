#include <string>
#include <map>
using namespace std;

map<string, int> s1, s2, gyo, hap;
typedef map<string, int>::iterator iter;

void set_map(string s, int cnt)
{
    for(int i = 0; i < s.size() - 1; i++)
    {
        char t1 = s[i], t2 = s[i+1];
        
        if(t1 >= 'a' && t1 <= 'z') t1 -= 32;
        else if (t1 < 'A' || t1 > 'Z') continue;
        
        if(t2 >= 'a' && t2 <= 'z') t2 -= 32;
        else if (t2 < 'A' || t2 > 'Z') continue;
        
        string st = ""; st += t1; st += t2;
        if(cnt == 0) ++s1[st];
        else if (cnt == 1) ++s2[st];
    }
}

int solution(string str1, string str2) {
    set_map(str1, 0); set_map(str2, 1);
    
    for(iter i = s1.begin(); i != s1.end(); i++) hap[i->first] = s1[i->first];
    for(iter i = s2.begin(); i != s2.end(); i++)
    {
        if(hap[i->first] < s2[i->first]) hap[i->first] = s2[i->first];
        
        if(s1[i->first] > 0)
        {
            if(s1[i->first] < s2[i->first]) gyo[i->first] = s1[i->first];
            else gyo[i->first] = s2[i->first];
        }
    }
    
    int bunza = 0, bunmo = 0;
    for(iter i = gyo.begin(); i != gyo.end(); i++) bunza += i->second;
    for(iter i = hap.begin(); i != hap.end(); i++) bunmo += i->second;

    if(bunmo == 0) return 65536;

    double val = (double) bunza / bunmo;
    
    int answer = val * 65536;
    return answer;
}