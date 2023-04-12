#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

set<int> set_de, set_pi;
typedef set<int>::reverse_iterator iter;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    for(int i = 0; i < n; i++) { if(deliveries[i] > 0) set_de.insert(i); if(pickups[i] > 0) set_pi.insert(i); }
    
    set_de.insert(-1); set_pi.insert(-1);
    
    while(true)
    {
        iter it1 = set_de.rbegin(); iter it2 = set_pi.rbegin();
        if(*it1 == -1 && *it2 == -1) break;
        
        int plusValue = *it1 > *it2 ? *it1 : *it2; answer += (plusValue+1) * 2;
         
        // 배달
        int cnt = cap;
        while(true)
        {
            it1 = set_de.rbegin();
            
            if(*it1 == -1 || cnt == 0) break;
            
            if(deliveries[*it1] <= cnt)
            {
                cnt -= deliveries[*it1]; deliveries[*it1] = 0; set_de.erase(*it1);
            }
            else
            {
                deliveries[*it1] -= cnt; cnt = 0;
            }
        }
        
        // 수거
        cnt = cap;
        while(true)
        {
            it2 = set_pi.rbegin();
            
            if(*it2 == -1 || cnt == 0) break;
            
            if(pickups[*it2] <= cnt)
            {
                cnt -= pickups[*it2]; pickups[*it2] = 0; set_pi.erase(*it2);
            }
            else
            {
                pickups[*it2] -= cnt; cnt = 0;
            }
        }
    }
    
    return answer;
}