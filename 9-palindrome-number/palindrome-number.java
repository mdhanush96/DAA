class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;

        if(x!=0 && x%10 == 0) return false;
        int num = x;
        int reminder = 0;
        // int temp = num;
        while(num>0){
            reminder = reminder * 10 + (num % 10);
            num = num/10;
        }
        if(reminder == x){
            return true;
        }
        return false;
    }
}