from math import inf

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if len( word1 ) < len( word2 ):
            return self.minDistance( word2, word1 )

        opt = [ [ 0 for _ in range( len(word2) + 1 ) ] for i in range( len( word1 ) + 1 ) ]

        for i in range( len( word1 ) + 1 ):
           opt[i][0] = i
        for j in range( len( word2 ) + 1 ):
            opt[0][j] = j

        for j in range( 1, len( word2 ) + 1 ):
            for i in range( 1, len( word1 ) + 1 ):

                vals = []
                d = 0 if word1[i - 1] == word2[j - 1] else 1
                vals.append( d + opt[i - 1][j - 1] )
                vals.append( 1 + opt[i - 1][j] )
                vals.append( 1 + opt[i][j - 1] )
                opt[i][j] = min( vals )

        return opt[-1][-1]

Solution().minDistance( "sea", "eat" )
