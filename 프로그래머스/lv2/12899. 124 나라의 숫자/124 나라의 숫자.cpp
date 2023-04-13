#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0)
    {
        int mok = n / 3;
        int namuzi = n % 3;
        
        string nstr = "";
        if(namuzi == 1) { nstr = "1"; }
        else if (namuzi == 2) { nstr = "2"; }
        else { nstr = "4"; --mok; }
        
        string tmp = nstr;
        tmp += answer;
        answer = tmp;
        
        n = mok;
    }
    
    return answer;
}