from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        k = len(words[0])
        n = len(words)
        res = []
        pool = Counter(words)

        for i in range( 0, len(s) - n * k + 1 ):
            
            j = i
            broken = False
            horizon = {}
            for h in range(n):

                if j + k > len(s):
                    broken = True
                    break

                subs = s[j : j + k]
                if subs not in pool:
                    broken = True
                    break
                
                if subs not in horizon:
                    horizon[subs] = 0
    
                horizon[subs] += 1
                j += k

            if not broken and horizon == pool:
                res.append(i)
    
        return res
