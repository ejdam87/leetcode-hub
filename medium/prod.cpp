#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int n = nums.size();
        std::vector<int> prod_0 = std::vector<int>(n, 1);
        prod_0[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prod_0[i] = prod_0[i - 1] * nums[i];
        }

        int prev = 1;
        for (int i = n - 1; i > 0; i--)
        {
            prod_0[i] = prod_0[i - 1] * prev;
            prev *= nums[i];
        }
        prod_0[0] = prev;
        return prod_0;
    }
};


void printVector(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << ' ' << v[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> nums = std::vector( {1,2,3,4} );
    Solution sol = Solution();
    printVector(sol.productExceptSelf(nums));
    return 0;
}
