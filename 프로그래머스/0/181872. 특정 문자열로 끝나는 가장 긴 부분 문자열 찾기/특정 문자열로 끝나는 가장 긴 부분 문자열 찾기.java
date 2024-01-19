import java.util.*;

class Solution {
    public String solution(String myString, String pat) {
        String answer = "";

        int pos = 0;
        while(true) {
            int tempPos = myString.indexOf(pat, pos+1);
            if(tempPos == -1) break;
            else pos = tempPos;
        }
        
        int len = pos + pat.length();
        
        
        for(int i = 0; i < len; i++) {
            answer += myString.charAt(i);
        }
        
        return answer;
    }
}