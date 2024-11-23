from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if nums == []:
            return 0

        snake = { num : None for num in nums }

        for num in nums:
            if num + 1 in snake:
                snake[num + 1] = num
        
        starts = [ x for x in snake if snake[x] is None ]

        inv_snake = { b : a for a, b in snake.items() if b is not None }
        best = 1
        for start in starts:
            current = 1

            if start not in inv_snake:
                continue

            x = inv_snake[start]
            while x in inv_snake:
                x = inv_snake[x]
                current += 1
            
            current += 1
            
            best = max(best, current)

        return best


print( Solution().longestConsecutive( [100,4,200,1,3,2] ) )
