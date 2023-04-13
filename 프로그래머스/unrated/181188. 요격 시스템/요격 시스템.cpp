#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TG
{
    int start, end;
        TG(int s, int e) { start = s; end = e; }

    bool operator<(const TG &tg) const
    {
        if(start == tg.start)
        {
            int len1 = end - start + 1, len2 = tg.end - tg.start + 1;
            return len1 > len2;
        }
        return start > tg.start;
    }
};

int solution(vector<vector<int>> targets) {
    priority_queue<TG> qu;
    for(int i = 0; i < targets.size(); i++) qu.push(TG(targets[i][0], targets[i][1]));

    int answer = 1;

    int currentStart = qu.top().start, currentEnd = qu.top().end; qu.pop();

    while(!qu.empty())
    {
        // cout << "현재 감지중... " << currentStart << " " << currentEnd << endl;

        int tempStart = qu.top().start, tempEnd = qu.top().end; qu.pop();

        // cout << tempStart << " " << tempEnd << endl;

        if(tempStart < currentEnd && currentStart < tempEnd)
        {
            if(tempStart > currentStart) currentStart = tempStart;
            if(tempEnd < currentEnd) currentEnd = tempEnd;
        }
        else
        {
            // cout << "새로운 폭격 미사일이 필요!" << endl;
            ++answer;
            currentStart = tempStart; currentEnd = tempEnd;
        }
    }

    // cout << "현재 감지중... " << currentStart << " " << currentEnd << endl;

    return answer;
}