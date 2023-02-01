#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i++)
    {
        string check = phone_book[i]; string check2 = phone_book[i+1];
        if(check2.size() >= check.size())
        {
            bool isSame = true;
            for(int i2 = 0; i2 < check.size(); i2++)
            {
                if(check[i2] != check2[i2]) { isSame = false; break; }
            }
            if(isSame)
            {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}