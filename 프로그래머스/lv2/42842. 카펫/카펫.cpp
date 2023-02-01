#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    brown = (brown - 4) / 2;
    vector<int> a; int m = brown/2;
    for(int s = 1; s <= m; s++)
    {
        int g = brown - s;
        if(g * s == yellow) { a.push_back(g+2); a.push_back(s+2); break; }
    }
    return a;
}