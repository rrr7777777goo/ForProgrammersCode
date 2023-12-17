#include <string>
#include <vector>
using namespace std;

int solution(int chicken) {
    int answer = 0;
    
    while(chicken >= 10) {
        int mok = chicken / 10;
        int namuzi = chicken % 10;
        answer += mok;
        chicken = namuzi;
        chicken += mok;
    }
    
    return answer;
}