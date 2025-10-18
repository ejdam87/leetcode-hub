from typing import List
import re


class Solution:
    def __init__(self) -> None:
        # expr -> list of possible values
        self.memo = {}
        self.ops = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
        }

    def _get_op_after(self, expression: str, parts: List[str], i: int) -> str | None:
        total_len = 0
        for j in range( i + 1 ):
            total_len += len(parts[j]) + 1
        
        if total_len >= len(expression):
            return None

        return expression[total_len - 1]


    def diffWaysToCompute(self, expression: str) -> List[int]:
        if expression in self.memo:
            return self.memo[expression]

        if len(expression) == 0:
            return []

        parts = re.split(r'[+\-*]', expression)

        if len(parts) == 1:
            res = [int(parts[0])]
        else:
            res = []
            n = int(parts[0])
            op = self._get_op_after(expression, parts, 0)

            # n + (...)
            rest1 = self.diffWaysToCompute( expression[len(parts[0]) + 1:] )
            print("Rest 1", expression, rest1)
            for subres in rest1:
                res.append( self.ops[op](n, subres) )

            # (n + m) * (...)
            m = int(parts[1])
            operand_1 = self.ops[op](n, m)
            print("OP1", expression, operand_1)
            op2 = self._get_op_after(expression, parts, 1)
            if op2:
                rest2 = self.diffWaysToCompute( expression[len(parts[0]) + 1 + len(parts[1]) + 1:] )
                print("Rest 2", expression, rest2)
                for operand_2 in rest2:
                    res.append( self.ops[op2](operand_1, operand_2) )

        if expression not in self.memo:
            self.memo[expression] = res
        
        return res


print( Solution().diffWaysToCompute("2*3-4*5") )
