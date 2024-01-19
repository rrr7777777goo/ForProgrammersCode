import java.util.*;

class Solution {
    public String[] solution(String my_string) {
        String[] answer = {};
        
        List<String> li = new ArrayList<>();
        
        String tmpStr = "";
        
        for(int i = 0; i < my_string.length(); i++) {
            if(my_string.charAt(i) == ' ') {
                li.add(tmpStr);
                tmpStr = "";
            } else {
                tmpStr += my_string.charAt(i);
            }
        }
        
        li.add(tmpStr);
        
        answer = li.toArray(new String[li.size()]);
        
        return answer;
    }
}