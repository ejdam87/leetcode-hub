#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int m = (left + right) / 2;

            if (nums[m] == target)
            {
                return m;
            }
            else if (left == right)
            {
                if (nums[m] < target)
                {
                    return m + 1;
                }
                return m;
            }
            else if (target > nums[m])
            {
                left = m + 1;
            }
            else
            {
                right = m - 1;
            }
        }

        if (left < nums.size())
        {
            if (nums[left] < target)
            {
                return left + 1;
            }
            else
            {
                return left;
            }
        }
        if (right >= 0)
        {
            if (nums[right] < target)
            {
                return right + 1;
            }
            else
            {
                return right;
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> nums = {3, 5, 7, 9, 10};
    Solution().searchInsert(nums, 8);
}