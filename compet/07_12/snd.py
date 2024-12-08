from typing import List


class Solution:
    def findMinimumTime(self, strength: List[int], K: int) -> int:
        x = 1
        energy = 0
        time = 0

        strength = sorted(strength)

        while len(strength) != 0:

            time += 1
            energy += x

            if energy >= strength[0]:

                print(strength, time)
                sm = -1
                for i in range(len(strength)):
                    if energy < strength[i]:
                        break
                    sm = i

                strength.pop(sm)
                x += K
                energy = 0

        return time

Solution().findMinimumTime( [7,3,6,18,22,50], 4 )
