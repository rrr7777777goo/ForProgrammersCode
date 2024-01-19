import java.util.*;
import java.util.Map.*;

class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        Map<Integer, Integer> ma = new HashMap<>();
    
        for(int i = 0; i < attendance.length; i++) {
            if(attendance[i]) {
                ma.put(i, rank[i]);
            }
        }
        
        List<Entry<Integer, Integer>> li = new ArrayList<Entry<Integer, Integer>>(ma.entrySet());
        
        Collections.sort(li, new Comparator<>() {
            @Override
            public int compare(Entry<Integer, Integer> e1, Entry<Integer, Integer> e2) {
                return e1.getValue().compareTo(e2.getValue());
            }
        });
        
        return 10000 * li.get(0).getKey() + 100 * li.get(1).getKey() + li.get(2).getKey();
    }
}