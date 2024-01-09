class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        
        long inputVal = x;
        for(int i = 0; i < n; i++) {
            answer[i] = inputVal;
            inputVal += x;
        }
        
        return answer;
    }
}