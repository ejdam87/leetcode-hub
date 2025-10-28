from typing import List

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        pair_mapping = {}

        for i in range( 0, len(row), 2 ):
            p1, p2 = row[i], row[i + 1]
            pair_mapping[p1] = (p1, p2)
            pair_mapping[p2] = (p1, p2)

        c = 0
        for i in range(0, len(row), 2 ):
            fst = i
            snd = i + 1

            f1, f2 = pair_mapping[fst]
            fst_other = f2 if f1 == fst else f1
            s1, s2 = pair_mapping[snd]
            snd_other = s2 if s1 == snd else s1

            if pair_mapping[fst] != pair_mapping[snd]:
                c += 1
                pair_mapping[fst] = (i, i + 1)
                pair_mapping[snd] = (i, i + 1)

                pair_mapping[fst_other] = (fst_other, snd_other)
                pair_mapping[snd_other] = (fst_other, snd_other)

        return c

print( Solution().minSwapsCouples( [5,4,2,6,3,1,0,7] ) )
