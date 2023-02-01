#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
         
    int answer = 0;

    for(int x = 0; x < A.size(); x++)
    {
        answer += (A[x] * B[x]);
    }
         
    return answer;
}