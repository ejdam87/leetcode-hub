from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def reconstruct(self, nodes: list[tuple[int, int]], start: int) -> tuple[ TreeNode, int ]:
        
        node = TreeNode()
        val, depth = nodes[start]
        node.val = val
        left, right, end = None, None, start + 1

        if start + 1 < len(nodes):
            nxt_depth = nodes[start + 1][1]
            if nxt_depth - 1 == depth:
                left, end = self.reconstruct(nodes, start + 1)

                if end < len(nodes):
                    nxt_depth = nodes[end][1]
                    if nxt_depth - 1 == depth:
                        right, end = self.reconstruct(nodes, end)

        node.left = left
        node.right = right
        return node, end

    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        vals = [int(val.strip()) for val in traversal.replace("-", " ").split(" ") if val.strip() != ""]
        nodes = []

        i = 0
        j = 0
        depth = 0

        while j < len(traversal):
            if traversal[j] == "-":
                depth += 1
                j += 1
            else:
                nodes.append( (vals[i], depth) )
                depth = 0
                i += 1
                while j < len(traversal) and traversal[j] != "-":
                    j += 1
        
        return self.reconstruct(nodes, 0)[0]

res = Solution().recoverFromPreorder( "1-2--3--4-5--6--7" )
print( res.right.val )
