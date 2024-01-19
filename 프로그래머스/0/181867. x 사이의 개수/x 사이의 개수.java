import java.util.*;

class Solution {
    public int[] solution(String myString) {
        int[] answer = {};
        
        List<Integer> li = new ArrayList<>();
        
        int cnt = 0;
        for(int i = 0; i < myString.length(); i++) {
            if(myString.charAt(i) == 'x') {
                li.add(cnt);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        li.add(cnt);
        
        answer = Arrays.stream(li.toArray(new Integer[li.size()])).mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}