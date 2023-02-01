#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int a = 0; a < arr.size(); a++) answer += arr[a];
    return answer / arr.size();
}