class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        
        for(int b = 0; b < queries.length; b++) {
            for(int a = 0; a < arr.length; a++) {
                if(a >= queries[b][0] && a <= queries[b][1] && a % queries[b][2] == 0) {
                    ++arr[a];
                }
            }
        }
        
        return arr;
    }
}