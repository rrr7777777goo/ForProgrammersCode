import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        
        List<Integer> li = new ArrayList<>();
        
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr[i]; j++) {
                li.add(arr[i]);
            }
        }
        
        answer = Arrays.stream(li.toArray(new Integer[li.size()])).mapToInt(Integer::intValue).toArray();
        return answer;
    }
}