#include <vector>
#include <iostream>

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        int res = 0;
        int num_pos = 0;
        int num_neg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                num_pos += 1;
            }
            else
            {
                num_neg += 1;
            }
        }

        for (int d = 0; d < 32; d++)
        {
            int subres = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                subres += (nums[i] % 2);
                nums[i] /= 2;
            }
            if (subres % 3 != 0)
            {
                res |= (1 << d);
            }
        }

        if (res == INT_MIN)
        {
            return res;
        }

        return num_pos % 3 == 0 ? -1 * res : res;
    }
};

int main()
{
    std::vector<int> vals = {2, 2, 2, 3, 3, -4, 3};
    std::cout << Solution().singleNumber( vals ) << '\n';
}
