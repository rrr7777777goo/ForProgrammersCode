class Solution {
    public int solution(int[] num_list) {
        int odd = 0;
        int even = 0;
        
        boolean isOdd = true;
        for(int i = 0; i < num_list.length; i++) {
            if(isOdd) {
                odd += num_list[i];
            } else {
                even += num_list[i];
            }
            
            isOdd = !isOdd;
        }
        
        return odd > even ? odd : even;
    }
}