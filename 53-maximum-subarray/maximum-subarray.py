class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr = nums[0]
        maxs= nums[0]

        for num in nums[1:]:
            curr = max(num,curr + num)
            maxs = max(maxs,curr)

        return maxs