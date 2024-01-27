import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        String[] answer = {};
        
        List<String> li = new ArrayList<>();
        
        for(int i = 0; i < strings.length; i++) {
            li.add(strings[i]);
        }
        
        Collections.sort(li, new Comparator<>() {
            @Override
            public int compare(String s1, String s2) {
                if(s1.charAt(n) == s2.charAt(n)) {
                    return s1.compareTo(s2);
                } else {
                    return s1.charAt(n) - s2.charAt(n);
                }
            }
        });
        
        answer = li.toArray(new String[li.size()]);
        return answer;
    }
}