from typing import List


class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        res: List[int] = nums+nums
        return res


nums = [1,2,1]


objeto = Solution()

res = objeto.getConcatenation(nums)

print(res)

