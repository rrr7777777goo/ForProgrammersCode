class Solution {
    public String solution(String my_string, int m, int c) {
        String answer = "";
        
        int cnt = 1;
        for(int i = 0; i < my_string.length(); i++) {
            if(cnt == c) answer += my_string.charAt(i);
            
            if(cnt == m) {
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        
        return answer;
    }
}