import java.util.*;

class Solution {
    public String[] solution(String myStr) {
        String[] answer = {};
        
        List<String> li = new ArrayList<>();
        
        String tmpStr = "";
        
        for(int i = 0; i < myStr.length(); i++) {
            if(myStr.charAt(i) == 'a' || myStr.charAt(i) == 'b' || myStr.charAt(i) == 'c') {
                if(tmpStr.compareTo("") != 0) {
                    li.add(tmpStr);
                    tmpStr = "";
                }
            } else {
                tmpStr += myStr.charAt(i);
            }
        }
        
        if(tmpStr.compareTo("") != 0) {
            li.add(tmpStr);
        }
        
        if(li.size() == 0) {
            answer = new String[1];
            answer[0] = "EMPTY";
        } else {
           answer = li.toArray(new String[li.size()]);
        }
        
        return answer;
    }
}