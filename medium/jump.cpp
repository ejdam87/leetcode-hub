#include <vector>
#include <iostream>

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        int n = nums.size();
        std::vector<bool> can = std::vector(n, false);
        can[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= nums[i]; j++)
            {
                if (can[i + j])
                {
                    can[i] = true;
                    break;
                }
            }
        }
        return can[0];
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
    std::vector<int> nums = std::vector( {3,2,1,1,4} );
    Solution sol = Solution();
    std::cout << sol.canJump(nums) << '\n';
    return 0;
}

