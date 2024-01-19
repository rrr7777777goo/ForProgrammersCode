import java.util.*;

class Solution {
    public int solution(String binomial) {
        int answer = 0;
    
        int a = 0;
        String strA = "";
        int b = 0;
        String strB = "";
        char op = ' ';
            
        for(int i = 0; i < binomial.length(); i++) {
            if(binomial.charAt(i) != ' ') {
                if(binomial.charAt(i) >= '0' && binomial.charAt(i) <= '9') {
                    if(op == ' ') {
                        strA += binomial.charAt(i);
                    } else {
                        strB += binomial.charAt(i);
                    }
                } else {
                    op = binomial.charAt(i);
                }
            }
        }
        
        switch(op) {
            case '+':
                answer = Integer.parseInt(strA) + Integer.parseInt(strB);
                break;
            case '-':
                answer = Integer.parseInt(strA) - Integer.parseInt(strB);
                break;
            case '*':
                answer = Integer.parseInt(strA) * Integer.parseInt(strB);
                break;
        }
        
        return answer;
    }
}