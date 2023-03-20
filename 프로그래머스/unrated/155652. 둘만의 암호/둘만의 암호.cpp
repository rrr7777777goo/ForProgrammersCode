#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, bool> isSkipWord;
map<char, char> changeWord;

string solution(string s, string skip, int index) {

    for(int i = 0; i < skip.size(); i++) isSkipWord[skip[i]] = true;

    string answer = "";

    for(char c = 'a'; c <= 'z'; c++)
    {
        char tmp = c;
        for(int i = 0; i < index; )
        {
            ++tmp; if(tmp > 'z') tmp -= 26;
            if(!isSkipWord[tmp]) i++;
        }
        changeWord[c] = tmp; 
    }

    for(int i = 0; i < s.size(); i++) answer += changeWord[s[i]];

    return answer;
}