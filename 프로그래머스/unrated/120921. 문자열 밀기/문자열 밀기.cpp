#include <string>
#include <vector>
#include <string>
using namespace std;

int solution(string A, string B) {
    int cnt = 0;
    int startA = 0;
    while(cnt < A.size()) {
        bool isSame = true;
        int idxA = startA;
        for(int idxB = 0; idxB < B.size(); idxB++) {
            if(B[idxB] != A[idxA]) {
                isSame = false;
                break;
            }
            idxA = (idxA + 1) % A.size();
        }
        
        if(isSame) return cnt;
        if(startA == 0) startA = A.size() - 1;
        else --startA;
        ++cnt;
    }
    
    
    return -1;
}