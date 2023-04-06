#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i = 0; i < array.size(); i++)
    {
        string str = to_string(array[i]);
        int cnt = 0;
        for(int x = 0; x < str.size(); x++) if(str[x] == '7') ++cnt;
        answer += cnt;
    }
    
    return answer;
}