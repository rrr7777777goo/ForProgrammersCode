#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> dDice;
vector<bool> divideTeam;

vector<int> teamA;
vector<int> teamB;

map<int, int> scoreCntA;
map<int, int> scoreCntB;

typedef map<int, int>::iterator iter;

int gs = 1;
int maxWin = 0;
vector<int> answer;

int tmpScore;
void settingMap(bool tAfB, int cnt) {
    if(cnt == teamA.size()) {
        if(tAfB) {
            ++scoreCntA[tmpScore];
        } else {
            ++scoreCntB[tmpScore];
        }
        return;
    }
    for(int i = 0; i < 6; i++) {
        if(tAfB) tmpScore += dDice[teamA[cnt]][i];
        else tmpScore += dDice[teamB[cnt]][i];
        settingMap(tAfB, cnt+1);
        if(tAfB) tmpScore -= dDice[teamA[cnt]][i];
        else tmpScore -= dDice[teamB[cnt]][i];
    }
}

void DFS(int cnt, int idx) {
    if(cnt == dDice.size() / 2) {
        teamA = vector<int>();
        teamB = vector<int>();
        for(int i = 0; i < divideTeam.size(); i++) {
            if(divideTeam[i]) teamA.push_back(i);
            else teamB.push_back(i);
        }
        scoreCntA.clear();
        scoreCntB.clear();
        
        settingMap(true, 0);
        settingMap(false, 0);
      
        scoreCntB[0] = 0;
        scoreCntB[10000] = 0;
        
        vector<int> bB = vector<int>(scoreCntB.size(), 0);
        iter it = scoreCntB.begin();
        int iii = 0;
        bB[iii++] = it->first;
        ++it; iter previt = scoreCntB.begin();
        for(; it != scoreCntB.end(); it++) {
            bB[iii++] = it->first;
            it->second += previt->second;
            ++previt;
        }
        
        int winA = 0;
        int draw = 0;
        int winB = 0;
        for(iter it = scoreCntA.begin(); it != scoreCntA.end(); it++) {
            
            int left = 0, right = bB.size() -1;
            while(left < right) {
                int mid = (left + right) / 2;
                if(it->first <= bB[mid]) {
                    right = mid;
                } else {
                    left = mid+1;
                }
            }
            
            if(bB[right] == it->first) {
                int wA = it->second * scoreCntB[bB[right-1]];
                int dr = it->second * (scoreCntB[bB[right]] - scoreCntB[bB[right-1]]);
                winA += wA;
                draw += dr;
            } else {
                int wA = it->second * scoreCntB[bB[right-1]];
                winA += wA;
            }
        }
        winB = gs - (winA + draw);
        
        if(winA > winB) {
            if(winA > maxWin) {
                maxWin = winA;
                answer = teamA;
            }
        } else if (winB > winA) {
            if(winB > maxWin) {
                maxWin = winB;
                answer = teamB;
            }
        }
        return;
    }
    
    for(int i = idx; i < dDice.size(); i++) {
        divideTeam[i] = true;
        DFS(cnt+1, i+1);
        divideTeam[i] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    dDice = dice;
    divideTeam = vector<bool>(dice.size(), false);
    
    for(int i = 0; i < dice.size(); i++) {
        gs *= 6;
    }
    
    divideTeam[0] = true;
    DFS(1, 1);
    
    for(int i = 0; i < answer.size(); i++) {
        ++answer[i];
    }
    return answer;
}