import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        int[] answer = new int[arr.length -1];
        if(arr.length == 1) {
            answer = new int[1];
            answer[0] = -1;
        } else {
            int min = -1;
        
            int[] backup = new int[arr.length];
            for(int i = 0; i < arr.length; i++) {
               backup[i] = arr[i];
            }
        
            Arrays.sort(arr);
            min = arr[0];
            
            int idx = 0;
            for(int i = 0; i < backup.length; i++) {
                if(backup[i] != min) {
                    answer[idx++] = backup[i];
                }
            }
        }

        return answer;
    }
}