import java.util.*;
import java.util.Map.*;

class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        int answer = 0;
        
        Map<Integer, Integer> ma = new HashMap<>();
        
        for(int i = 0; i < rank.length; i++) {
            if(attendance[i]) {
                ma.put(i, rank[i]);
            }
        }
        
        List<Entry<Integer, Integer>> li = new ArrayList<>(ma.entrySet());
        
        Collections.sort(li, new Comparator<>() {
            @Override
            public int compare(Entry<Integer, Integer> e1, Entry<Integer, Integer>e2) {
                return e1.getValue().compareTo(e2.getValue());
            }
        });
        
        return li.get(0).getKey() * 10000 + li.get(1).getKey() * 100 + li.get(2).getKey();
    }
}