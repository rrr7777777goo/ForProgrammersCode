class Solution {
    public String solution(String phone_number) {
        int cnt = 0;
        
        String returnPN = "";
        
        for(int i = phone_number.length() -1; i >= 0; i--) {
            if(cnt == 4) {
                returnPN = "*" + returnPN;
            } else {
                returnPN = "" + phone_number.charAt(i) + returnPN;
                ++cnt;
            }
        }
        return returnPN;
    }
}