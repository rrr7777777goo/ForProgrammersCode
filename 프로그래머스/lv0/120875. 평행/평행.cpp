#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int
    bunza_0_1 = dots[0][0] - dots[1][0], bunmo_0_1 = dots[0][1] - dots[1][1],
    bunza_0_2 = dots[0][0] - dots[2][0], bunmo_0_2 = dots[0][1] - dots[2][1],
    bunza_0_3 = dots[0][0] - dots[3][0], bunmo_0_3 = dots[0][1] - dots[3][1],
    bunza_1_2 = dots[1][0] - dots[2][0], bunmo_1_2 = dots[1][1] - dots[2][1],
    bunza_1_3 = dots[1][0] - dots[3][0], bunmo_1_3 = dots[1][1] - dots[3][1],
    bunza_2_3 = dots[2][0] - dots[3][0], bunmo_2_3 = dots[2][1] - dots[3][1];
    
    if(bunza_0_1 * bunmo_2_3 == bunza_2_3 * bunmo_0_1 || bunza_0_2 * bunmo_1_3 == bunza_1_3 * bunmo_0_2 || bunza_0_3 * bunmo_1_2 == bunza_1_2 * bunmo_0_3) return 1;
    
    return 0;
}