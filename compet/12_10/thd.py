
def is_subsequence(A, B, forb):
    i, j = 0, 0

    while i < len(A) and j < len(B):

        if j in forb:
            j += 1
            continue

        if A[i] == B[j]:
            i += 1
        j += 1

    return i == len(A)



class Solution(object):

    def __init__(self):
        self.memo = {}

    def rem_rec(self, source, pattern, forb, i, targets):
        if i == len(targets):
            return 0

        tot1 = 0
        forb.append( targets[i] )
        if is_subsequence(pattern, source, forb):
            if tuple(forb) in self.memo:
                tot1 = self.memo[tuple(forb)]
            else:
                tot1 = self.rem_rec(source, pattern, forb + [targets[i]], i+1, targets) + 1
                self.memo[tuple(forb)] = tot1

        forb.pop()

        if tuple(forb) in self.memo:
            tot2 = self.memo[tuple(forb)]
        else:
            tot2 = self.rem_rec(source, pattern, forb, i+1, targets)
            self.memo[tuple(forb)] = tot1

        return max(tot1, tot2)

    def maxRemovals(self, source, pattern, targetIndices):
        """
        :type source: str
        :type pattern: str
        :type targetIndices: List[int]
        :rtype: int
        """
        return self.rem_rec(source, pattern, [], 0, targetIndices)

print( Solution().maxRemovals( source = "dd", pattern = "d", targetIndices = [0] ) )
