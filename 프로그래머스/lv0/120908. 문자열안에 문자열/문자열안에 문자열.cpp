#include <string>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    
    int s1 = str1.size(), s2 = str2.size();
    for(int i = 0; i <= s1 - s2; i++)
    {
        bool isFind = true;
        for(int j = 0; j < str2.size(); j++) { if(str1[i+j] != str2[j]) { isFind = false; break; } }
        if(isFind) { answer = 1; break; }
    }

    return answer;
}