from typing import List

from collections import Counter


class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        c = Counter(nums)
        keys = sorted(c.keys())
        freqs = [ c[k] for k in keys ]

        opt = [ 0 for _ in range( len(keys) ) ]
        opt[0] = keys[0] * freqs[0]

        for i in range( 1, len(keys) ):

            # not take
            a = opt[i - 1]

            # take
            b = keys[i] * freqs[i]
            prev = keys[i - 1] if i - 1 >= 0 else -1
            prev_prev = keys[i - 2] if i - 2 >= 0 else -1

            if prev != -1 and keys[i] - prev > 1:
                b += opt[i - 1]
            elif prev_prev != -1:
                b += opt[i - 2]

            opt[i] = max(a, b)
        
        return opt[-1]
