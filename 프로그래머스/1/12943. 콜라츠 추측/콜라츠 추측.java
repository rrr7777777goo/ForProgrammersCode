class Solution {
    public int solution(int num) {
        int cnt = 0;
        long nu = num;
        
        while(cnt < 500 && nu != 1) {
            if(nu % 2 == 0) {
                nu /= 2;
            } else {
                nu = nu * 3 + 1;
            }
            ++cnt;
        }
        
        return nu != 1 ? -1 : cnt;
    }
}