
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):

    def sum_rec(self, node):

        if node is None:
            return []

        l = self.sum_rec(node.left)
        r = self.sum_rec(node.right)

        if l == r == []:
            return [str(node.val)]

        return [str(node.val) + v for v in l + r]

    def sumNumbers(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """

        return sum( [ int(x) for x in self.sum_rec(root) ] )


root = TreeNode(1)
r = TreeNode(3)
root.right = r

print(Solution().sumNumbers(root))
