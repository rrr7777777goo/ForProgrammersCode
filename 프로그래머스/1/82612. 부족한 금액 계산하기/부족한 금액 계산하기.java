class Solution {
    public long solution(int price, int money, int count) {
        long answer = 0;
        
        long sum = 0;
        
        long currentPrice = price;
        for(int i = 0; i < count; i++) {
            sum += currentPrice;
            currentPrice += price;
        }
        
        if(sum > money) answer = sum - money;
        
        return answer;
    }
}