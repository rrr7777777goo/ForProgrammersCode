class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        
        boolean[] isFind = new boolean[10];
        
        for(int i = 0; i < numbers.length; i++) {
            isFind[numbers[i]] = true;
        }
        
        for(int i = 1; i < 10; i++) {
            if(!isFind[i]) answer += i;
        }
        
        return answer;
    }
}