import itertools

class Solution(object):
    def validSequence(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: List[int]
        """

        seq = []

        possible = [[] for _ in range( len(word2) )]

        for i, c in enumerate(word2):
            for j, c2 in enumerate(word1):
                if c == c2 and len(word1) - j >= len(word2) -i:
                    possible[i].append(j)

        print(possible)
        last = -1
        empty = 0
        for i, poss in enumerate(possible):
            
            if empty == 2:
                return []

            success = False

            for j in poss:
                if j <= last:
                    continue

                success = True
                last = j
                seq.append(j)
                break
            
            if not success:
                empty += 1
                seq.append(last + 1)
                last += 1

        if empty == 2:
            return []
        return seq

print( Solution().validSequence("ccbccccbcc", "b") )
