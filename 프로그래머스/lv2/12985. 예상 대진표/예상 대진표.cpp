using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    while(true)
    {
        if(((a-b) == 1 && a%2 == 0) || ((b-a) == 1 && b%2 == 0)) break;
        
        if((a%2) == 1) a += 1;
        if((b%2) == 1) b += 1;
        a /= 2;
        b /= 2;
        
        ++answer;
    }
    
    return answer;
}