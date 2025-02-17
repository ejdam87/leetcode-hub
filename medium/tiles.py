from itertools import chain, permutations

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        all_vars = list(self.all_variations(tiles))
        res_set = set()

        for var in all_vars:
            res_set.add( "".join( var ) )

        return len(res_set) - 1

    def all_variations(self, iterable):
        s = list(iterable)
        return chain.from_iterable(permutations(s, r) for r in range(len(s)+1))
