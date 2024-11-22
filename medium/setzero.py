from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        for i in range( len(matrix) ):
            for j in range( len(matrix[0]) ):
                if matrix[i][j] == 0:
                    for k in range( len(matrix) ):
                        matrix[k][j] = None if matrix[k][j] != 0 else 0
                    for k in range( len( matrix[0] ) ):
                        matrix[i][k] = None if matrix[i][k] != 0 else 0

        for i in range( len(matrix) ):
            for j in range( len(matrix[0]) ):
                if matrix[i][j] is None:
                    matrix[i][j] = 0
