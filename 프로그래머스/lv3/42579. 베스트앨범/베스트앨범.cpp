#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Play
{
public:
    int idx = -1;
    int playCount = 0;
    
    Play(int idx, int playCount) { this->idx = idx; this->playCount = playCount; }
    
    bool operator< (const Play &p) const
    {
        if(playCount == p.playCount) return idx > p.idx;
        else return playCount < p.playCount;
    }
};

class Genre
{
public:
    int totalCount = 0;
    priority_queue<Play> qu_Play;
    
    bool operator< (const Genre &g) const
    {
        return totalCount < g.totalCount;
    }
};

map<string, Genre> mmaa;
typedef map<string, Genre>::iterator iter;

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    for(int i = 0; i < genres.size(); i++)
    {
        mmaa[genres[i]].totalCount += plays[i];
        mmaa[genres[i]].qu_Play.push(Play(i, plays[i]));
    }
    
    priority_queue<Genre> qG;
    vector<int> answer;
    
    for(iter i = mmaa.begin(); i != mmaa.end(); i++) qG.push(i->second);
    while(!qG.empty())
    {
        Genre g = qG.top();
        int ccount = 2;
        while(ccount > 0 && !g.qu_Play.empty())
        {
            answer.push_back(g.qu_Play.top().idx);
            g.qu_Play.pop();
            --ccount;
        }
        qG.pop();
    }
    
    return answer;
}