from collections import Counter
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        actual_sum = sum(nums)
        actual_set_sum = sum(set(nums))

        duplicate = actual_sum - actual_set_sum
        expected_sum = n * (n + 1) // 2
        missing = expected_sum - actual_set_sum

        return [duplicate, missing]
        