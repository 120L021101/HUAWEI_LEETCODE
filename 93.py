from typing import *
class Solution:

    def is_legal(self, num_str: str) -> bool:
        if num_str.startswith('0') and len(num_str) > 1:
            return False
        if len(num_str) == 0:
            return False
        num = int(num_str)
        return 0 <= num <= 255

    def construct(self, s: str, idx_ls: List[int]) -> str:
        return s[:idx_ls[0]] + '.' + s[idx_ls[0] : idx_ls[1]] + '.' + s[idx_ls[1] : idx_ls[2]] + '.' + s[idx_ls[2]:]       

    def dfs_check(self, s: str, idx: int, ans: List[str], idx_ls: List[int]):
        if len(idx_ls) == 3:
            if self.is_legal(s[idx:]):
                ans.append(self.construct(s, idx_ls))
            return
        s_idx = idx + 1
        while s_idx <= len(s) and self.is_legal(s[idx : s_idx]):
            idx_ls.append(s_idx)
            self.dfs_check(s, s_idx, ans, idx_ls)
            idx_ls.pop()
            s_idx += 1

    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        self.dfs_check(s, 0, ans, [])
        return ans