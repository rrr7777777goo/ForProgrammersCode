#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int bunza = numer1 * denom2 + numer2 * denom1; 
    int bunmo = denom1 * denom2;
    
    int small = bunza < bunmo ? bunza : bunmo;
    for(int i = small; i >= 1; i--)
    {
        if(bunza%i == 0 && bunmo%i == 0)
        {
            bunza /= i;
            bunmo /= i;
            break;
        }
    }
    
    answer.push_back(bunza);
    answer.push_back(bunmo);
    return answer;
}