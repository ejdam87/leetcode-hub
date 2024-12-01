#include <vector>
#include <algorithm>

class Solution
{
private:
    void permuteRec(int i, std::vector<int>& nums, std::vector<std::vector<int>>& res)
    {
        if (i == nums.size())
        {
            res.push_back( nums );
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {
            std::swap( nums[i], nums[j] );
            permuteRec(i + 1, nums, res);
            std::swap( nums[i], nums[j] );
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> res = {};
        permuteRec(0, nums, res);
        return res;
    }
};
