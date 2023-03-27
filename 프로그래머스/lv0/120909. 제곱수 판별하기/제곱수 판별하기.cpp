#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

map<int, bool> isZGU;

int solution(int n) {
    double maxi = sqrt(1000000);
    for(int i = 1; i <= maxi; i++) isZGU[i * i] = true;
    
    return isZGU[n] ? 1 : 2;
}