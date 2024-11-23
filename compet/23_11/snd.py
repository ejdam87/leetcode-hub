import string
from typing import List

ALPHABET = string.ascii_lowercase

ALPHABET_TO_INDEX = { ALPHABET[i] : i for i in range(26) }

class Solution:
    def shiftDistance(self, s: str, t: str, nextCost: List[int], previousCost: List[int]) -> int:

        res = 0
        for i in range( len(s) ):
            a = ALPHABET_TO_INDEX[ s[i] ]
            b = ALPHABET_TO_INDEX[ t[i] ]

            prev_cost = 0
            a_prev = a
            next_cost = 0
            a_next = a

            while a_prev != b:
                prev_cost += previousCost[a_prev]
                a_prev = (a_prev - 1) % 26

            while a_next != b:
                next_cost += nextCost[a_next]
                a_next = (a_next + 1) % 26
            
            res += min(prev_cost, next_cost)

        return res


nextcost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
prevcost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
print( Solution().shiftDistance("leet", "code", nextcost, prevcost) )
