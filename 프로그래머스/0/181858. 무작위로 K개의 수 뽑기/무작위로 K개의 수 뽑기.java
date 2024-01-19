import java.util.*;

class Solution {
    public int[] solution(int[] arr, int k) {
        int[] answer = {};
        
        List<Integer> li = new ArrayList<>();
        
        boolean[] isSelected = new boolean[100001];
        
        for(int i = 0; i < arr.length; i++) {
            if(!isSelected[arr[i]]) {
                isSelected[arr[i]] = true;
                li.add(arr[i]);
            }
            if(li.size() == k) break;
        }
        
        while(li.size() < k) {
            li.add(-1);
        }
        
        answer = Arrays.stream(li.toArray(new Integer[li.size()])).mapToInt(Integer::intValue).toArray();
        return answer;
    }
}