#include <vector>
#include <unordered_map>

class Solution
{
    public:
        long long countBadPairs(std::vector<int>& nums)
        {
            std::unordered_map<int, long long> diffs;
            for ( int i = 0; i < nums.size(); i++ )
            {
                diffs[ nums[i] - i ]++;
            }

            long long total = nums.size() * (nums.size() - 1) / 2;
            for ( auto [k, v] : diffs )
            {
                if ( v > 1 )
                {
                    total -= (v * (v - 1)) / 2;
                }
            }

            return total;
        }
    };
