from typing import *
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        l, r = 0, 0
        maxVal, curVal = 0, 0
        occured = set()
        numLen = len(nums)
        while r < numLen:
            if nums[r] in occured:
                while nums[l] != nums[r]:
                    occured.remove(nums[l])
                    curVal -= nums[l]
                    l += 1
                occured.remove(nums[l])
                curVal -= nums[l]
                l += 1
                continue
            occured.add(nums[r])
            curVal += nums[r]
            maxVal = max(maxVal, curVal)
            r += 1
        return maxVal 
