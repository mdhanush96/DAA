class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        c = 0
        a = 0
        for i in range(len(nums)):
            if nums[i]==1:
                c+=1
                a = max(a,c)
            else:
                c=0
        return a

