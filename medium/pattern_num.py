class Solution:

    def smallestPossible(self, pattern: str, current: str, i: int, used: set[int]) -> str | None:
        
        if i == len(pattern) + 1:
            return current

        if i == 0:
            start, stop = 1, 10

        elif pattern[i - 1] == "I":
            start, stop = int(current[i - 1]) + 1, 10
        else:
            start, stop = 1, int(current[i - 1]) 

        for d in range(start, stop):
            if d in used:
                continue

            used.add(d)
            res = self.smallestPossible(pattern, current + str(d), i + 1, used)
            if res is not None:
                return res
            used.remove(d)

        return None

    def smallestNumber(self, pattern: str) -> str:
        return self.smallestPossible(pattern, "", 0, set())

Solution().smallestNumber("IIIDIDDD")
