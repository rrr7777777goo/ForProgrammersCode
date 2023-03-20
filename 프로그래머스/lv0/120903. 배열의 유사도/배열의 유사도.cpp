#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> ma;

int solution(vector<string> s1, vector<string> s2) {
    for(int i = 0; i < s1.size(); i++) ++ma[s1[i]];
    
    int answer = 0;
    for(int i = 0; i < s2.size(); i++) if(ma[s2[i]] > 0) { ++answer; --ma[s2[i]]; }
    return answer;
}