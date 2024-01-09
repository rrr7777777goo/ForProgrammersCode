class Solution {
    boolean solution(String s) {
        int pP = 0;
        int yY = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'p' || s.charAt(i) == 'P') ++pP;
            else if (s.charAt(i) == 'y' || s.charAt(i) == 'Y') ++yY;
        }
        
        return pP == yY;
    }
}