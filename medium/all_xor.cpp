#include <vector>

class Solution
{
public:
    int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int res = 0;

        for ( int num : nums1 )
        {
            if ( m % 2 == 1 )
            {
                res ^= num;
            }
        }

        for ( int num : nums2 )
        {
            if ( n % 2 == 1 )
            {
                res ^= num;
            }
        }

        return res;
    }
};
