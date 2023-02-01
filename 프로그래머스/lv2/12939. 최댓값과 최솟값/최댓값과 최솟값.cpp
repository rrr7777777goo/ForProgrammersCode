#include <string>
#include <vector>

using namespace std;

string solution(string s) { s += ' ';
    bool noValue = true;
    int mini , maxi;
    
    string tmp = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            if(noValue)
            {
                mini = stoi(tmp); maxi = stoi(tmp);
                tmp = "";
                noValue = false;
            }
            else
            {
                int ti = stoi(tmp);
                if(mini > ti) mini = ti; if(maxi < ti) maxi = ti;
                tmp = "";
            }
        }
        else tmp += s[i];
    }
    
    string ans = "";
    ans += to_string(mini);
    ans += " ";
    ans += to_string(maxi);
    return ans;
}