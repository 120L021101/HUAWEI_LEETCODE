class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        retOp = []
        indexMap = {}
        for i, val in enumerate(arr):
            indexMap[val] = i
        
        pick_val = len(arr)
        while pick_val >= 1:
            idx = indexMap[pick_val]
            expect_idx = pick_val - 1
            retOp.append(idx + 1)
            retOp.append(expect_idx + 1)
            arr = arr[:idx + 1][::-1] + arr[idx + 1:]
            arr = arr[:expect_idx + 1][::-1] + arr[expect_idx + 1:]
            for i, val in enumerate(arr):
                indexMap[val] = i
            pick_val -= 1
        return retOp