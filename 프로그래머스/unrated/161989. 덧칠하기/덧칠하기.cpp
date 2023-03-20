#include <string>
#include <vector>
using namespace std;

vector<bool> isPaint;
int solution(int n, int m, vector<int> section) {
    isPaint = vector<bool>(n+1, true);
    
    for(int i = 0; i < section.size(); i++) isPaint[section[i]] = false;

    int answer = 0;
    
    for(int x = 1; x <= (n - m + 1); x++)
    {
        if(!isPaint[x])
        {
            ++answer;
            for(int y = x; y <= (x + m - 1); y++) isPaint[y] = true;
        }
    }
    
    for(int x = (n - m + 2); x <= n; x++)
    {
        
        if(!isPaint[x]) { ++answer; break; }
    }
    
    
    return answer;
}