class Solution {    
    public int solution(int n, int k) {
        int answer = 0;
        String chgStr = Integer.toString(n, k);
        String[] arr = chgStr.split("0");
        
        for(int i = 0; i<arr.length; i++) {
            String getStr = arr[i];
            
            if(getStr.equals("")) continue;
            
            if(check(Long.parseLong(getStr))) {
                answer += 1;
            }
        }
        
        return answer;
    }
    
    public boolean check(long target) {
        if(target <= 1) return false;
        
        for(int i = 2; i<=Math.sqrt(target); i++) {
            if(target % i == 0) return false;
        }
        
        return true;
    }
}