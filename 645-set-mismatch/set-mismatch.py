class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        seen = []
        n= len(nums)
        dublicate = 0
        Original = 0
        sum2 = sum1 = 0
        for i in nums:
            sum2 = sum2+i
            if i in seen:
                dublicate = i
            seen.append(i)

        sum1 = (n*(n+1))//2

        return [dublicate,sum1-(sum2-dublicate)]
