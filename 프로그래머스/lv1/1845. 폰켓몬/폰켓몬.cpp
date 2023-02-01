#include <vector>
using namespace std;

int cnt;
bool isAlreadyCheck[200001];
int solution(vector<int> nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        if(!isAlreadyCheck[nums[i]])
        {
            isAlreadyCheck[nums[i]] = true;
            ++cnt;
        }
    }
    
    int maxi = nums.size()/ 2;
    return maxi < cnt ? maxi : cnt;
}