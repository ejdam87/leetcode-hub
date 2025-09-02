from typing import List


class Solution:
    def get_upper_left_closure(self, point: List[int], points: List[List[int]]) -> List[int]:
        res = []
        for other in points:
            if other[0] == point[0] and other[1] == point[1]:
                continue

            if other[0] <= point[0] and other[1] >= point[1]:
                res.append( other )

        return res

    def violates_property(self, point, candidate, closure) -> bool:
        for other in closure:
            if other == candidate:
                continue

            if candidate[0] <= other[0] <= point[0] and candidate[1] >= other[1] >= point[1]:
                return True
        
        return False

    def numberOfPairs(self, points: List[List[int]]) -> int:
        res = 0

        for point in points:
            closure = self.get_upper_left_closure(point, points)
            for candidate in closure:
                if not self.violates_property(point, candidate, closure):
                    res += 1

        return res

print( Solution().numberOfPairs([[6,2],[4,4],[2,6]]) )
