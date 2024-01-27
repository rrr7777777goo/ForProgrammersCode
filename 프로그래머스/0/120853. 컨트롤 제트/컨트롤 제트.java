import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int previous = -1;
        String str = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9' || s.charAt(i) == '-') {
                str += s.charAt(i);
            } else if(s.charAt(i) == 'Z') {
                answer -= previous;
                previous = -1;
            } else {
                if(str.compareTo("") != 0) {
                    previous = Integer.parseInt(str);
                    str = "";
                    answer += previous;
                }
            }
        }
        if(str.compareTo("") != 0) {
            previous = Integer.parseInt(str);
            str = "";
            answer += previous;
        }

        return answer;
    }
}