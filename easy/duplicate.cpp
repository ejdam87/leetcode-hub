#include <vector>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < std::min( nums.size(), std::size_t(i + k + 1) ); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }

        return false;
    }
};
