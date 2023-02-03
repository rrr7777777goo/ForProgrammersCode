using namespace std;

int solution(int n, long long l, long long r) {
    int ans = 0;

    for (long long i = l; i <= r; i++)
    {
        if (i % 5 == 3) continue;
        
        long long tmp = i; bool isPlus = false;
        while (true)
        {
            if (tmp % 5 == 0) tmp = tmp / 5;
            else tmp = (tmp / 5) + 1;

            if (tmp % 5 == 3) break;
            else if (tmp <= 5)
            {
                isPlus = true;
                break;
            }
        }
        if (isPlus) ans++;
    }

    return ans;
}