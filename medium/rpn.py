from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        ops = {
            "+": lambda x, y : x + y,
            "-": lambda x, y : x - y,
            "*": lambda x, y : x * y,
            "/": lambda x, y : int(x / y),
        }
        for token in tokens:
            if token not in ops:
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                stack.append( ops[token]( a, b ) )
        
        return stack[-1]

Solution().evalRPN( ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] )
