#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1) arr[0] = -1;
    else
    {
        int mini = arr[0], mI = 0;
        for(int i = 1; i < arr.size(); i++)
        {
            if(mini > arr[i])
            {
                mini = arr[i];
                mI = i;
            }
        }
        arr.erase(arr.begin() + mI);
    }
    return arr;
}