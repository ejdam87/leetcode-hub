from typing import List

# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution:
    
    def construct_rec( self, grid, l, r, t, b ):

        val = -1
        all_same = True

        for i in range( t, b + 1 ):
            for j in range( l, r + 1 ):
                if val == -1:
                    val = grid[ i ][ j ]
                elif grid[ i ][ j ] != val:
                    all_same = False
                    break
            
            if not all_same:
                break
        
        if all_same:
            return Node( val, True, None, None, None, None )
        
        xm = ( l + r ) // 2
        ym = ( t + b ) // 2

        tl = self.construct_rec( grid, l, xm, t, ym )
        tr = self.construct_rec( grid, xm + 1, r, t, ym )
        bl = self.construct_rec( grid, l, xm, ym + 1, b )
        br = self.construct_rec( grid, xm + 1, r, ym + 1, b )
        return Node( val, False, tl, tr, bl, br )
 
    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.construct_rec( grid, 0, len( grid[0] ) - 1, 0, len( grid ) - 1 )
