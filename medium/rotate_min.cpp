#include <vector>
#include <algorithm>

class Solution
{
public:
    int findMin(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while ( left <= right )
        {
            int m = (left + right) / 2;

            if ( right - left >= 2 && nums[m] < nums[m - 1] && nums[m] < nums[m + 1] )
            {
                return nums[m];
            }
            else if ( left == right )
            {
                return nums[m];
            }
            else if ( m == left )
            {
                return std::min(nums[m], nums[m + 1]);
            }
            else if (m == right)
            {
                return std::min(nums[m - 1], nums[m]);
            }
            else if ( nums[left] > nums[m - 1] )
            {
                right = m - 1;
            }
            else if ( nums[right] < nums[m + 1] )
            {
                left = m + 1;
            }
            else if (nums[m - 1] < nums[m + 1])
            {
                right = m - 1;
            }
            else
            {
                left = m + 1;
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> v = {1, 2};
    Solution().findMin( v );
}