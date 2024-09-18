#include <vector>
#include <iostream>
#include <algorithm>

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

        if (n == 1)
        {
            return 0;
        }

        int fst_valley = -1;
        for (int i = 0; i < n; i++)
        {
            if (is_valley(prices, i))
            {
                fst_valley = i;
                break;
            }
        }

        int lst_peak = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (is_peak(prices, i))
            {
                lst_peak = i;
                break;
            }
        }

        int lowest = -1;
        for (int i = lst_peak; i >= 0; i--)
        {
            if (is_valley(prices, i))
            {
                if (lowest == -1 || prices[i] <= prices[lowest])
                {
                    lowest = i;
                }
            }
        }

        if (lst_peak <= fst_valley)
        {
            return 0;
        }

        int highest = -1;
        for (int j = fst_valley; j < n; j++)
        {
            if (is_peak(prices, j))
            {
                if (highest == -1 || prices[highest] <= prices[j])
                {
                    highest = j;
                }
            }
        }

        for (int i = lowest; i < n; i++)
        {
            res = std::max( res, prices[i] - prices[lowest] );
        }

        for (int i = 0; i <= highest; i++)
        {
            res = std::max( res, prices[highest] - prices[i] );
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
    std::vector<int> nums = std::vector( {7,6,4,3,1} );
    Solution sol = Solution();
    std::cout << sol.maxProfit(nums) << '\n';
    return 0;
}
