from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_height = max(heights)

        best = 0
        surpassing = list(range(len(heights)))
        for height in range(0, max_height + 1):

            best_this_height = 0
            current = 0
            prev_i = None
            new_surpassing = []
            for i in surpassing:
                if heights[i] >= height:
                    new_surpassing.append(i)

                if (prev_i is None or prev_i == i - 1) and heights[i] >= height:
                    current += 1
                    prev_i = i
                else:
                    best_this_height = max(best_this_height, current)
                    if heights[i] >= height:
                        current = 1
                        prev_i = i
                    else:
                        current = 0
                        prev_i = None

            best_this_height = max(best_this_height, current)
            best = max( best, height * best_this_height )
            surpassing = new_surpassing

        return best


print(Solution().largestRectangleArea([4,2,0,3,2,5]))
