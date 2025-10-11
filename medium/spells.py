from typing import List, Set

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        return self.maximum_damage(power, len(power) - 1, set())

    def maximum_damage(self, spells: List[int], ceiling: int, forbidden: Set[int]) -> int:
        if ceiling < 0:
            return 0

        add = 0
        j = ceiling
        while j >= 0 and spells[ceiling] == spells[j]:
            add += spells[j]
            j -= 1

        # take if can
        if spells[ceiling] not in forbidden:
            rest_take = self.maximum_damage(spells, j, forbidden | {spells[ceiling] - 2, spells[ceiling] - 1, spells[ceiling] + 1, spells[ceiling] + 2})
        else:
            add = 0
            rest_take = -1

        # do not take
        rest_not_take = self.maximum_damage(spells, j, forbidden)

        return max( add + rest_take, rest_not_take )

# Solution().maximumTotalDamage([1,1,3])
