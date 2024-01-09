class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        
        for(int current = left; current <= right; current++) {
            int cnt = 0;
            for(int y = 1; y <= Math.sqrt(current); y++) {
                if(current % y == 0) {
                    if(current / y == y) {
                        ++cnt;
                    } else {
                        cnt += 2;
                    }
                } 
            }
            if(cnt % 2 == 0) {
                answer += current;
            } else {
                answer -= current;
            }
        }
         
        return answer;
    }
}