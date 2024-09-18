#include <vector>
#include <iostream>

class Solution
{
public:
    int jump(std::vector<int>& nums)
    {
        int n = nums.size();
        std::vector<int> steps = std::vector(n, -1);
        steps[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= nums[i]; j++)
            {
                if (i + j < n && steps[i + j] != -1)
                {
                    if (steps[i] == -1)
                    {
                        steps[i] = 1 + steps[i + j];
                    }
                    else
                    {
                        steps[i] = std::min(steps[i], 1 + steps[i + j]);
                    }
                }
            }
        }
        return steps[0];
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
    std::vector<int> nums = std::vector( {2,3,1,1,4} );
    Solution sol = Solution();
    std::cout << sol.jump(nums) << '\n';
    return 0;
}

