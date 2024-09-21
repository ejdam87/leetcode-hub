#include <vector>
#include <iostream>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int n = gas.size();
        int gas_sum = 0;
        int cost_sum = 0;

        std::vector<int> starters = {};

        for (int i = 0; i < n; i++)
        {
            gas_sum += gas[i];
            cost_sum += cost[i];
            if (gas[i] - cost[i] > 0)
            {
                starters.push_back(i);
            }
        }

        if (gas_sum < cost_sum)
        {
            return -1;
        }

        if (starters.size() == 0)
        {
            return 0;
        }

        for (int i : starters)
        {
            int sm = 0;
            bool success = true;
            for (int j = 0; j < n; j++)
            {
                sm += gas[ (i + j) % n ];
                sm -= cost[ (i + j) % n ];
                if (sm < 0)
                {
                    success = false;
                    break;
                }
            }

            if (success)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> gas = std::vector( {5,8,2,8} );
    std::vector<int> cost = std::vector( {6,5,6,6} );
    Solution sol = Solution();
    std::cout << sol.canCompleteCircuit(gas, cost) << '\n';
    return 0;
}
