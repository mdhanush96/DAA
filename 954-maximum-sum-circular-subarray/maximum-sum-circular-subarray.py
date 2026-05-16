class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        maxsum = minsum = currmax = currmin = totalsum = nums[0]

        for num in nums[1:]:
            currmax = max(num,currmax + num)
            maxsum = max(maxsum, currmax)

            currmin = min(currmin + num , num)
            minsum = min(currmin,minsum)

            totalsum += num

        circularmax = totalsum - minsum

        if circularmax == 0 or circularmax < maxsum:
            return maxsum

        return circularmax