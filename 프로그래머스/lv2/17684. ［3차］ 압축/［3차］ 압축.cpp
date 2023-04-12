#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> dictionary;

vector<int> solution(string msg) {
    int nextNumber = 27;
    
    vector<int> answer;
    
    for(int a = 'A'; a <= 'Z'; a++) { string s = ""; s += a; dictionary[s] = a - 64; }
    
    string sav = "";
    for(int i = 0; i < msg.size(); i++)
    {
        string tmp = sav;
        tmp += msg[i];
        
        if(dictionary[tmp] != 0) { sav = tmp; }
        else
        {
            dictionary[tmp] = nextNumber++;
            answer.push_back(dictionary[sav]);
            sav = ""; sav += msg[i];
        }
    }
    answer.push_back(dictionary[sav]);
    
    return answer;
}