import java.util.*;

class Solution {
    public String[] solution(String my_string) {
        String[] answer = {};
        
        List<String> li = new ArrayList<>();
        
        String tmpStr = "";
        for(int i = my_string.length()-1; i >= 0; i--) {
            tmpStr = my_string.charAt(i) + tmpStr;
            li.add(tmpStr);
        }
        
        Collections.sort(li);
        answer = li.toArray(new String[li.size()]);
        return answer;
    }
}