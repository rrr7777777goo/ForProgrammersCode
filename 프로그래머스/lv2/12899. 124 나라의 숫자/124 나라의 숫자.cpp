#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0)
    {
        int mok = n / 3, namuzi = n % 3;
        if(namuzi == 0)
        {
            --mok;
            namuzi = 4;
        }
        string tmp_str = "";
        tmp_str = '0' + namuzi;
        answer = tmp_str + answer;
        n = mok;
    }

    return answer;
}