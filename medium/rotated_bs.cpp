#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while ( left <= right )
        {
            int m = (left + right) / 2;
            if ( nums[m] == target )
            {
                return m;
            }
            if (m - 1 >= 0 && nums[left] <= nums[m - 1])
            {
                if ( m - 1 >= left && target >= nums[left] && target <= nums[m - 1] )
                {
                    right = m - 1;
                }
                else
                {
                    left = m + 1;
                }
            }
            else if ( m + 1 < nums.size() )
            {
                if ( m + 1 <= right && target >= nums[ m + 1 ] && target <= nums[right] )
                {
                    left = m + 1;
                }
                else
                {
                    right = m - 1;
                }
            }
            else
            {
                break;
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> pool = {3,4,5,6,7,8,1,2};
    Solution().search(pool, 2);
}
