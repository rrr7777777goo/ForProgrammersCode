using namespace std;

int solution(int n)
{
    int a = 0;
    
    while(n > 0)
    {
        if(n%2 == 0) n /= 2; 
        else { n -= 1; ++a; }
    }
    
    return a;
}