from typing import List, Optional

class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        if len(preorder) == 0:
            return None

        root = TreeNode()
        root.val = preorder[0]

        if len(preorder) == 1:
            return root

        fst_right = postorder[-2]
        i = preorder.index(fst_right)
        left_preorder = []
        right_preorder = []

        for j in range( 1, len(preorder) ):
            if j < i:
                left_preorder.append(preorder[j])
            else:
                right_preorder.append(preorder[j])

        left_postorder = []
        right_postorder = []

        for i in range(len(postorder) - 1):
            if postorder[i] in left_preorder:
                left_postorder.append(postorder[i])
            else:
                right_postorder.append(postorder[i])

        root.left = self.constructFromPrePost(left_preorder, left_postorder)
        root.right = self.constructFromPrePost(right_preorder, right_postorder)
        return root


Solution().constructFromPrePost( [1,2,4,5,3,6,7], [4,5,2,6,7,3,1] )
