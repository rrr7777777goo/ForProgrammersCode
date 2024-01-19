import java.util.*;

class Solution {
    public int[] solution(int start_num, int end_num) {
        int[] answer = {};
        
        List<Integer> li = new ArrayList<>();
        
        while(start_num <= end_num) {
            li.add(start_num++);
        }
        
        answer = Arrays.stream(li.toArray(new Integer[li.size()])).mapToInt(Integer::intValue).toArray();

        return answer;
    }
}