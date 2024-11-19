#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        std::make_heap( nums.begin(), nums.end() );

        for (int i = 0; i < k - 1; i++)
        {
            std::pop_heap( nums.begin(), nums.end() );
            nums.pop_back();
        }

        return nums[0];
    }
};

int main()
{
    std::vector<int> v = {3,2,3,1,2,4,5,5,6};
    std::cout << Solution().findKthLargest(v, 4) << '\n';
}
