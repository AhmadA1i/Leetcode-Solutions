class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        prefixSum = 0
        minLen = float('inf')

        for r in range(len(nums)):
            prefixSum += nums[r]
            while prefixSum >= target:
                minLen = min(minLen, r - l + 1)
                prefixSum -= nums[l]
                l += 1

        return 0 if minLen == float('inf') else minLen



        
