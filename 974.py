class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        modCount = {0 : 1}
        count = 0
        sumVal = 0
        for i, num in enumerate(nums):
            sumVal += num
            modKey = sumVal % k
            count += modCount.get(modKey, 0)
            modCount[modKey] = modCount.get(modKey, 0) + 1
        
        return count