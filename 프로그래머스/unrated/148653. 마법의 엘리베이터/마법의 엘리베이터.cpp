#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int cnt = 0;
    while(storey > 0)
    {
        int na = storey % 10;
        if(na >= 6) { na = 10 - na; storey += na; }
        else if(na == 5)
        {
            int k = (storey / 10) % 10;
            if(k >= 5) { storey += na; }
        }
        cnt += na;
        storey /= 10;
    }
    return cnt;
}