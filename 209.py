class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_length = None
        left, right = 0, 0
        current_sum = 0
        length = len(nums)
        while right != length:
            current_sum += nums[right]
            current_length = right - left + 1
            while current_sum >= target:
                if min_length is None or min_length > current_length:
                    min_length = current_length
                current_sum -= nums[left]
                left += 1
                current_length -= 1
            right += 1
        return min_length if min_length is not None else 0 
    