class Solution:

    def kthHappy(self, n: int, current: str) -> str | None:
        if len(current) == n:
            if self.k == 1:
                return current
            else:
                self.k -= 1
                return None
        
        for c in ['a', 'b', 'c']:
            if len(current) > 0 and current[-1] == c:
                continue

            subres = self.kthHappy(n, current + c)
            if subres:
                return subres

        return ""

    def getHappyString(self, n: int, k: int) -> str:
        self.k = k
        return self.kthHappy(n, "")
