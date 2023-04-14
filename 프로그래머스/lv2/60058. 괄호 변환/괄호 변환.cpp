#include <string>
#include <vector>
using namespace std;

string FUNC(string p)
{
    string u = "", v = "";
    
    bool isCorrect = true;
    int cnt_C = 0, cnt_D = 0;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '(') ++cnt_C;
        else if (p[i] == ')') ++cnt_D;
        
        if(cnt_C < cnt_D && isCorrect) { isCorrect = false; }
        else if(cnt_C == cnt_D)
        {
            u = p.substr(0, i+1);
            if(i < p.size()-1) v = p.substr(i+1, -1);
            break;
        }
    }

    if(v.size() > 0) v = FUNC(v);
    
    string z = "";
    if(isCorrect) { z = u; z += v; }
    else
    {
        z = "("; z += v; z += ")";
        
        for(int i = 1; i < u.size()-1; i++)
        {
            if(u[i] == '(') z += ")";
            else z += "(";
        }
    }
    
    return z;
}


string solution(string p) {
    return FUNC(p);
}