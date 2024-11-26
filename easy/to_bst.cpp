#include <vector>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode* createRec(std::vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int m = (left + right) / 2;
        TreeNode* root = new TreeNode( nums[m] );
        root -> left = createRec(nums, left, m - 1);
        root -> right = createRec(nums, m + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        return createRec(nums, 0, nums.size() - 1);
    }
};

int main()
{
    std::vector<int> nums = {1, 3};
    TreeNode* root = Solution().sortedArrayToBST(nums);
    std::cout << root -> val << '\n';
}
