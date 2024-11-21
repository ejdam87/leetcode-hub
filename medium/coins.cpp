#include <vector>
#include <iostream>

class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        // opt(n) = min( opt(n - a1), opt(n - a2), ... ) + 1
        std::vector<int> opt = std::vector<int>(amount + 1, 0);

        for (int i = 1; i <= amount; i++)
        {
            int best = 1000000; // assuming amount < 1000000
            for (int coin : coins)
            {
                int k = i - coin < 0 ? 1000000 : opt[i - coin];
                best = std::min(best, k);
            }

            opt[i] = best + 1;
        }

        return opt[amount] > 1000000 ? -1 : opt[amount];
    }
};

int main()
{
    std::vector<int> coins = {1, 2, 5};

    std::cout << Solution().coinChange(coins, 16) << '\n';
}
