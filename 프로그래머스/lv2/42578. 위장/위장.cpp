#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> ma;
typedef map<string, int>::iterator iter;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0; i < clothes.size(); i++) ma[clothes[i][1]] += 1;
    
    for(iter it = ma.begin(); it != ma.end(); it++) answer *= (it->second + 1);
    
    return (answer-1);
}