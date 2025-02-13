#include <vector>
#include <queue>

class Solution
{
    public:
        int minOperations(std::vector<int>& nums, int k)
        {
            std::priority_queue<long long, std::vector<long long> , std::greater<long long>> heap;
            for ( auto num : nums )
            {
                heap.push( num );
            }

            int ops = 0;

            while ( heap.size() > 1 )
            {
                long long a = heap.top();
                heap.pop();
                long long b = heap.top();
                heap.pop();

                if ( a >= k )
                {
                    break;
                }

                heap.push( std::min( a, b ) * 2 + std::max( a, b ) );
                ops++;
            }

            return ops;
        }
};
