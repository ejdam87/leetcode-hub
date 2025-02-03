#include <vector>


class Solution
{
public:
    int longestMonotonicSubarray(std::vector<int>& nums)
    {
        int increase = 1;
        int increase_best = 1;

        for ( int i = 0; i < nums.size() - 1; i++ )
        {
            if ( nums[i] < nums[i + 1] )
            {
                increase++;
            }
            else
            {
                increase_best = std::max(increase_best, increase);
                increase = 1;
            }
        }
        increase_best = std::max(increase_best, increase);

        int decrease = 1;
        int decrease_best = 1;
        for ( int i = 0; i < nums.size() - 1; i++ )
        {
            if ( nums[i] > nums[i + 1] )
            {
                decrease++;
            }
            else
            {
                decrease_best = std::max(decrease_best, decrease);
                decrease = 1;
            }
        }
        decrease_best = std::max(decrease_best, decrease);

        return std::max(increase_best, decrease_best);
    }
};
