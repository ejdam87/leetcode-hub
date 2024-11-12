class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        s_strs = [ (s, "".join(sorted(s))) for s in strs ]
        res = { ss : [] for s, ss in s_strs }

        for s, ss in s_strs:
            res[ ss ].append(s)

        return list(res.values())


print( Solution().groupAnagrams( ["eat","tea","tan","ate","nat","bat"] ) )
