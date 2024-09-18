#include <vector>
#include <iostream>

class Solution
{
public:

    bool is_valley(std::vector<int>& prices, int i)
    {
        int n = prices.size();
        if (i > 0 && i < n - 1)
        {
            return prices[i - 1] >= prices[i] && prices[i] <= prices[i + 1];
        }
        else if (i == 0)
        {
            return prices[i] <= prices[i + 1];
        }
        else if (i == n - 1)
        {
            return prices[i - 1] >= prices[i];
        }
        else
        {
            return false;
        }
    }

    bool is_peak(std::vector<int>& prices, int i)
    {
        int n = prices.size();
        if (i > 0 && i < n - 1)
        {
            return prices[i - 1] <= prices[i] && prices[i] >= prices[i + 1];
        }
        else if (i == 0)
        {
            return prices[i] >= prices[i + 1];
        }
        else if (i == n - 1)
        {
            return prices[i - 1] <= prices[i];
        }
        else
        {
            return false;
        }
    }

    int maxProfit(std::vector<int>& prices)
    {
        int res = 0;
        int n = prices.size();

        if (n <= 1)
        {
            return 0;
        }

        int i = 0;
        int j = 0;

        while (j < n)
        {
            while (i < n && !is_valley(prices, i))
            {
                i++;
            }

            j = i;
            while (j < n && !is_peak(prices, j))
            {
                j++;
            }

            if (j < n)
            {
                res += (prices[j] - prices[i]);
            }

            if (i == j)
            {
                j = i + 1;
            }

            i = j;
        }

        return res;
    }
};

void printVector(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << ' ' << v[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> nums = std::vector( {1, 2, 3, 4, 5} );
    Solution sol = Solution();
    std::cout << sol.maxProfit(nums) << '\n';
    return 0;
}
