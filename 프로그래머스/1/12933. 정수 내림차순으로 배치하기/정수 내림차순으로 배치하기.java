class Solution {
    public long solution(long n) {
        int[] cnt = new int[10];
        String str = Long.toString(n);
        
        for(int i = str.length() - 1; i >= 0; i--) {
            ++cnt[str.charAt(i) - '0'];
        }
        
        String newStr = "";
        
        for(int i = 9; i >= 0; i--) {
            while(cnt[i] > 0) {
                newStr += (char) ('0' + i);
                --cnt[i];
            }
        }

        long answer = Long.parseLong(newStr);
        return answer;
    }
}