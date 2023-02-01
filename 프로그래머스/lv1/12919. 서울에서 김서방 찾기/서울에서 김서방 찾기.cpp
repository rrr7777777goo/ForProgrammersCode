#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int f = -1;

    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i].compare("Kim") == 0) { f = i; break; }
    }
    
    string x = "";
    x += "김서방은 "; x += to_string(f); x += "에 있다";
    return x;
}