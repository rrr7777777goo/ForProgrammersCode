#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int i2 = 1; i2 <= i; i2++) cout << "*";
        cout << "\n";
    }
    
    return 0;
}