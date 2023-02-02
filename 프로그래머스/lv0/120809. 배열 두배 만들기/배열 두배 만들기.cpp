#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> n) {
    for(int i = 0; i < n.size(); i++) n[i] *= 2;
    return n;
}