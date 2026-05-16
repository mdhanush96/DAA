class Solution:
    def findMin(self, nums: List[int]) -> int:
        min = nums[0]
        for i in range(1,len(nums)):
            if min > nums[i]:
                min = nums[i]
        
        return min