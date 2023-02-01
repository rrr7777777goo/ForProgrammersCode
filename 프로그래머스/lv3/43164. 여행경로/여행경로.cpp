#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Curr
{
    int cnt = 0;
    vector<string> vec_str;
    vector<bool> isUsed;
};
queue<Curr> qu, tmp_qu, reset_qu;

struct Info_Ticket
{
    int idx;
    string dest;

    Info_Ticket(int i, string des)
    {
        idx = i;
        dest = des;
    }

    bool operator<(const Info_Ticket &ti) const
    {
        if(dest.compare(ti.dest) == 0) return idx < ti.idx;
        else return dest.compare(ti.dest) < 0;
    }
};

map<string, vector<Info_Ticket>> map_Ti;
typedef map<string, vector<Info_Ticket>>::iterator iter;

vector<string> solution(vector<vector<string>> tickets) {

    for(int i = 0; i < tickets.size(); i++) map_Ti[tickets[i][0]].push_back(Info_Ticket(i, tickets[i][1]));
    for(iter i = map_Ti.begin(); i != map_Ti.end(); i++) sort((i->second).begin(), (i->second).end());


    Curr firstCurr; 
    firstCurr.vec_str.push_back("ICN");
    vector<bool> tvb(tickets.size(), false); firstCurr.isUsed = tvb;

    qu.push(firstCurr);

    vector<string> answer;

    bool isFind = false;
    while(!isFind)
    {
        tmp_qu = reset_qu;

        while(!qu.empty())
        {
            Curr cc = qu.front(); qu.pop();
            string x = cc.vec_str[cc.vec_str.size() - 1];

           for(int i = 0; i < map_Ti[x].size(); i++)
           {
              if( !cc.isUsed[map_Ti[x][i].idx] )
              {
                 ++cc.cnt;
                 cc.isUsed[map_Ti[x][i].idx] = true;
                 cc.vec_str.push_back(map_Ti[x][i].dest);

                 if(cc.cnt == tickets.size()) {isFind = true; answer = cc.vec_str; break;}
                 else tmp_qu.push(cc);

                 cc.vec_str.pop_back();
                 cc.isUsed[map_Ti[x][i].idx] = false;
                 --cc.cnt;
              }
           }
            if(isFind) break;
        }
        if(!isFind) qu = tmp_qu;
    }

    return answer;
}