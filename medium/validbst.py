from typing import Optional
from math import inf

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode], low=-inf, high=inf) -> bool:

        if root is None:
            return True

        if low < root.val < high:
            return self.isValidBST( root.left, low, root.val ) and self.isValidBST( root.right, root.val, high )

        return False
