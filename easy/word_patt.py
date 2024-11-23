class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        words = s.split(" ")
        if len(pattern) != len(words):
            return False
        
        iso = {}
        vals = set()

        for i in range( len(pattern) ):
            if pattern[i] not in iso:
                if words[i] in vals:
                    return False
                iso[ pattern[i] ] = words[i]
                vals.add(words[i])
            
            proj = iso[ pattern[i] ]
            if proj != words[i]:
                return False

        return True

print( Solution().wordPattern( "abba", "dog cat cat dog" ) )

