class Solution {
    public int[] shuffle(int[] nums, int n) {
        int temp[] = new int[nums.length] ;
        int a = 0;
        for(int i=0;i<n;i++){
            temp[a++] = nums[i];
            temp[a++] = nums[i+n];
            // a+=2;
            // i++;
            

        }
        return temp;
    }
}