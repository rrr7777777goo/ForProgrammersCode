#include <string>
#include <vector>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    vector<string> cache; vector<int> rI;
    for(int i = 0; i < cacheSize; i++) { cache.push_back("---"); rI.push_back(-1); }
    
    int answer = 0;
    
    if(cacheSize == 0) return cities.size() * 5;
    
    for(int i = 0; i < cities.size(); i++)
    {
        for(int a = 0; a < cities[i].size(); a++) if(cities[i][a] >= 'A' && cities[i][a] <= 'Z') cities[i][a] += 32;
        
        int lru = 100000; bool isFinish = false;
        for(int c = 0; c < cache.size(); c++)
        {
            if(rI[c] == -1)
            {
                cache[c] = cities[i];
                rI[c] = i;
                answer += 5;
                isFinish = true; break;
            }
            else
            {
                if(cache[c].compare(cities[i]) == 0)
                {
                    rI[c] = i;
                    answer += 1;
                    isFinish = true; break;
                }
                else
                {
                    if(lru == 100000) lru = c;
                    else if(rI[c] < rI[lru]) lru = c;
                }
            }
        }
        if(!isFinish)
        {
                cache[lru] = cities[i];
                rI[lru] = i;
                answer += 5;
        }
    }
    
    return answer;
}