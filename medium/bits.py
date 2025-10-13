from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        ones = [0 for i in range(n + 1)]

        # 0 1 10 11 100
        for i in range(1, n + 1):
            print(i)
            # last bit is zero
            if i % 2 == 0:
                ones[i] = ones[i // 2]
            # last bit is one
            else:
                ones[i] = ones[i // 2] + 1

        return ones

print( Solution().countBits(2) )
