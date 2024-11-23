
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        iso = {}
        vals = set()

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            if s[i] not in iso:
                if t[i] in vals:
                    return False

                iso[ s[i] ] = t[i]
                vals.add( t[i] )

            proj = iso[ s[i] ]
            if t[i] != proj:
                return False

        return True
