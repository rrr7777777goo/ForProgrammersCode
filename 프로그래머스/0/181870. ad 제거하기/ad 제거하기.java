import java.util.*;

class Solution {
    public String[] solution(String[] strArr) {
        String[] answer = {};
        
        List<String> li = new ArrayList<>();
        
        for(int i = 0; i < strArr.length; i++) {
            if(strArr[i].indexOf("ad") == -1) {
                li.add(strArr[i]);
            }
        }
        
        answer = li.toArray(new String[li.size()]);
        
        return answer;
    }
}