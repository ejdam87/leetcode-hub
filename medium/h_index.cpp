#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int hIndex(std::vector<int>& citations)
    {
        std::sort(citations.begin(), citations.end());
        int h = 0;
        int n = citations.size();
        for (int i = 0; i < n; i++)
        {
            if( n - i >= citations[i] )
            {
                h = citations[i];
            }
            else if (citations[i] >= i)
            {
                h = std::max(h, n - i);
            }
        }

        return h;

    }
};

int main()
{
    std::vector<int> nums = std::vector( {1,3,1} );
    Solution sol = Solution();
    std::cout << sol.hIndex(nums) << '\n';
    return 0;
}

