#include <vector>

class Solution
{
public:
    int findPeakElement(std::vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while ( low <= high )
        {
            int m = (low + high) / 2;

            if (m - 1 < 0 && m + 1 >= nums.size())
            {
                return m;
            }
            else if ( m - 1 < 0 )
            {
                if (nums[m] > nums[m + 1])
                {
                    return m;
                }
                else
                {
                    low = m + 1;
                }
            }
            else if (m + 1 >= nums.size())
            {
                if (nums[m] > nums[m - 1])
                {
                    return m;
                }
                else
                {
                    high = m;
                }
            }
            else if ( nums[m] > nums[m - 1] && nums[m] > nums[m + 1] )
            {
                return m;
            }
            else if ( nums[m] > nums[m - 1] )
            {
                low = m + 1;
            }
            else
            {
                high = m;
            }

        }

        return -1;
    }
};