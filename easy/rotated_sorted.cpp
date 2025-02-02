#include <vector>
#include <algorithm>

class Solution
{
public:
    bool check(std::vector<int>& nums)
    {
        int mi = std::distance(nums.begin(), std::min_element(nums.begin(), nums.end()));
        int n = nums.size();

        std::vector<int> mins_is;
        for ( int i = 0; i < n; i++ )
        {
            if ( nums[i] == nums[mi] )
            {
                mins_is.push_back( i );
            }
        }

        for ( int min_i : mins_is )
        {
            bool success = true;
            int prev = min_i;
            for ( int i = (min_i + 1) % n; i != min_i; i = (i + 1) % n )
            {
                if ( nums[prev] > nums[i] )
                {
                    success = false;
                    break;
                }
                prev = i;
            }

            if ( success )
            {
                return true;
            }
        }

        return false;
    }
};
