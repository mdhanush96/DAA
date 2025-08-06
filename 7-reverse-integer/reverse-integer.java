class Solution {
    public int reverse(int x) {
        int reminder = 0;
        int num = 0;
        while(x!=0){
            num = x%10;
            if(reminder > Integer.MAX_VALUE/10 || (reminder > Integer.MAX_VALUE && num > 7)){
                return 0;
            }
            else if (reminder < Integer.MIN_VALUE / 10 || (reminder<Integer.MIN_VALUE && num < -8)) return 0;
            
            reminder = reminder * 10 + num;
            x = x/10;
        }
        
        return reminder;
    }
}