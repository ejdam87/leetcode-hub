#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        if ( !std::binary_search(nums.begin(), nums.end(), target) )
        {
            return {-1, -1};
        }

        int a = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int b = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {a, b};
    }
};
