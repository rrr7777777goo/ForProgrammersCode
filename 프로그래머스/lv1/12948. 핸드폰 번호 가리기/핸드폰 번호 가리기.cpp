#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    
    int cnt = 1;
    for(int i = phone_number.size() - 1; i >= 0; i--)
    {
        if(cnt > 4) phone_number[i] = '*';
        ++cnt;
    }
    
    return phone_number;
}