import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {

        List<Integer> li = new ArrayList<>();
        
        Arrays.sort(arr);
        
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] % divisor == 0) {
                li.add(arr[i]);
            }
        }
        
        int[] answer = {};
        if(li.size() == 0) {
            answer = new int[1];
            answer[0] = -1;
        } else {
            answer = new int[li.size()];
            
            for(int i = 0; i < li.size(); i++) {
                answer[i] = li.get(i);
            }
        }
        
        return answer;
    }
}