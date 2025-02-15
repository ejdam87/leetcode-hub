class Solution:
    def can_partition(self, target: int, num: str, start: int) -> bool:

        if start >= len(num):
            return target == 0

        current = ""
        for i in range( start, len(num) ):
            current += num[i]
            if self.can_partition(target - int(current), num, i + 1):
                return True

        return False

    def punishmentNumber(self, n: int) -> int:
        total = 0
        for i in range(1, n + 1):
            square = i * i
            if self.can_partition(i, str(square), 0):
                total += square

        return total

Solution().punishmentNumber(10)
