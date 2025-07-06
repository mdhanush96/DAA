class Solution {
    public int searchInsert(int[] nums, int target) {
        int num = 0;
        int size = nums.length;
        for(int i =0;i< size;i++){
            if(nums[i] == target){
                num = i;
                return num;
            }
        }
        for(int i=size-1;i>=0;i--){
            if(nums[i]<target){
                num = i+1;
                return num;
            }
        }
        return num;

    }
}