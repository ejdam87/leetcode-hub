class Solution:
    def numSub(self, s: str) -> int:
        
        lens = []
        prev = 0

        for d in s:
            if d == "0":
                if prev != 0:
                    lens.append(prev)
                    prev = 0
            else:
                prev += 1
        
        if prev != 0:
            lens.append(prev)

        total = 0
        for l in lens:
            total += l * (l + 1) // 2
            total %= (10 ** 9) + 7
        
        return total

# 3 + 2 + 1
print( Solution().numSub("0110111") )
