class Solution {
    public boolean solution(int x) {
        String str = Integer.toString(x);
        
        int h = 0;
        for(int i = 0; i < str.length(); i++) {
            h += str.charAt(i) - '0';
        }
        
        return x % h == 0 ? true : false;
    }
}