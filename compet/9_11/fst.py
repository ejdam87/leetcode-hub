class Solution(object):
    def prod(self, n):
        res = 1
        for digit in str(n):
            res *= int(digit)
        return res

    def smallestNumber(self, n, t):
        """
        :type n: int
        :type t: int
        :rtype: int
        """
        while True:
            if self.prod(n) % t == 0:
                return n
            n += 1
