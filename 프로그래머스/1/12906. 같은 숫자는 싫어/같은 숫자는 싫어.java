import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        List<Integer> li = new ArrayList<>();
        
        li.add(arr[0]);
        for(int i = 1; i < arr.length; i++) {
            if(li.get(li.size() - 1) == arr[i]) continue;
            li.add(arr[i]);
        }
        
        return li.stream().mapToInt(i -> i).toArray();
    }
}