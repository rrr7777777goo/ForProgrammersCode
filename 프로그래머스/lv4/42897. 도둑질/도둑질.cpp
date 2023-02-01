#include <string>
#include <vector>
using namespace std;

vector<int> dp_001(1000000, 0);
vector<int> dp_002(1000000, 0);

int answer;
int solution(vector<int> money) {
    
    int idx_001 = 0, idx_002 = 0;
    for(int i = 0; i < money.size(); i++)
    {
        if(i <= money.size()-2)
        {
            if(idx_001 <= 1) dp_001[idx_001] = money[i];
            else if(idx_001 == 2) dp_001[idx_001] = money[i] + dp_001[idx_001-2];
            else dp_001[idx_001] = max(money[i] + dp_001[idx_001-2], money[i] + dp_001[idx_001-3]);
            
            if(answer < dp_001[idx_001]) answer = dp_001[idx_001];
            ++idx_001;
        }
        if(i >= 1)
        {
            if(idx_002 <= 1) dp_002[idx_002] = money[i];
            else if(idx_002 == 2) dp_002[idx_002] = money[i] + dp_002[0];
            else dp_002[idx_002] = max(money[i] + dp_002[idx_002-2], money[i] + dp_002[idx_002-3]);
            
            if(answer < dp_002[idx_002]) answer = dp_002[idx_002];
            ++idx_002;
        }

    }
    
    return answer;
}