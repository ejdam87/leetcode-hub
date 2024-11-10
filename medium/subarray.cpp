#include <vector>
#include <iostream>

class Solution
{
public:

    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        int sum = 0;
        int smallest = nums.size() + 1;

        while (right < nums.size())
        {
            while (sum < target && right < nums.size())
            {
                sum += nums[right];
                right++;
            }

            while (sum >= target)
            {
                smallest = std::min(smallest, right - left);
                sum -= nums[left];
                left++;
            }
        }

        return smallest == nums.size() + 1 ? 0 : smallest;
    }
};

int main()
{
    std::vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    std::cout << Solution().minSubArrayLen(target, nums) << '\n';
}
