#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string u = s.substr(1, s.size()-1);
    if(s[0] == '+') return stoi(u);
    else if (s[0] == '-') return -1 * stoi(u);
    else return stoi(s);
}