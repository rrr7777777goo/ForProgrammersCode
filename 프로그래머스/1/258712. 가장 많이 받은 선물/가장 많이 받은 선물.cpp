#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> ma;
    for(int i = 0; i < friends.size(); i++) {
        ma[friends[i]] = i;
    }
    vector<int> presentScore(friends.size(), 0);
    vector<vector<int>> give_take(friends.size(), vector<int>(friends.size(), 0));
    
    for(int i = 0; i < gifts.size(); i++) {
        bool isSecond = false;
        string name001 = "";
        string name002 = "";
        for(int a = 0; a < gifts[i].size(); a++) {
            if(gifts[i][a] == ' ') {
                isSecond = true;
            } else {
                if(isSecond) {
                    name002 += gifts[i][a];
                } else {
                    name001 += gifts[i][a];
                }
            }
        }
        ++give_take[ma[name001]][ma[name002]];
        ++presentScore[ma[name001]];
        --presentScore[ma[name002]];
    }
    
    int answer = 0;
    vector<int> nextMonthPresents(friends.size(), 0);
    
    for(int y = 0; y < friends.size()-1; y++) {
        for(int x = y+1; x < friends.size(); x++) {
            if(x == y) continue;
            if(give_take[ma[friends[y]]][ma[friends[x]]] > give_take[ma[friends[x]]][ma[friends[y]]]) {
                ++nextMonthPresents[ma[friends[y]]];
            }
            else if(give_take[ma[friends[y]]][ma[friends[x]]] < give_take[ma[friends[x]]][ma[friends[y]]]) {
                ++nextMonthPresents[ma[friends[x]]];
            }
            else {
                if(presentScore[ma[friends[y]]] > presentScore[ma[friends[x]]]) {
                    ++nextMonthPresents[ma[friends[y]]];
                } else if(presentScore[ma[friends[y]]] < presentScore[ma[friends[x]]]) {
                    ++nextMonthPresents[ma[friends[x]]];
                }
            }
        }
    }
    
    
    for(int i = 0; i < friends.size(); i++) {
        if(nextMonthPresents[i] > answer) answer = nextMonthPresents[i];
    }
    
    return answer;
}