class Solution {
    public String solution(String[] seoul) {
        int posKim = 0;
        
        for(int i = 0; i < seoul.length; i++) {
            if(seoul[i].compareTo("Kim") == 0) {
                posKim = i;
                break;
            }
        }
        
        String answer = Integer.toString(posKim);
        return "김서방은 " + answer + "에 있다";
    }
}