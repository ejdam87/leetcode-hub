#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }

        std::vector<std::string> res = {};
        int left = nums[0];
        int right = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - 1 == right)
            {
                right = nums[i];
            }
            else
            {
                if (left == right)
                {
                    res.push_back(std::to_string(left));
                }
                else
                {
                    std::string subres = std::to_string(left);
                    subres += "->";
                    subres += std::to_string(right);
                    res.push_back(subres);
                }

                left = nums[i];
                right = nums[i];
            }
        }

        if (left == right)
        {
            res.push_back(std::to_string(left));
        }
        else
        {
            std::string subres = std::to_string(left);
            subres += "->";
            subres += std::to_string(right);
            res.push_back(subres);
        }
    
        return res;
    }
};
