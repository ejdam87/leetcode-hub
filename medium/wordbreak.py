from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # can[n] = True if last k are word and can[n - k]

        can = [False for _ in range( len(s) + 1 )]

        can[0] = True

        for i in range( len(s) + 1 ):
            for word in wordDict:
                c = can[ i - len(word) ] if i - len(word) >= 0 else False
                if i - len(word) < 0:
                    continue

                if s[ i - len(word) : i ] == word and c:
                    can[i] = True

        return can[ len(s) ]

d = ["leet", "code", "boomer"]
print( Solution().wordBreak( "leetboomerleet", d ) )
