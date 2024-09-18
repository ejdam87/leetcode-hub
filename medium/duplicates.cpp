#include <iostream>
#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        int k = 1;
        int head = 1;
        int unique = nums[0];
        int seen = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == unique && seen < 2)
            {
                std::swap(nums[head], nums[i]);
                head++;
                seen++;
                k++;
            }
            else if (nums[i] != unique)
            {
                unique = nums[i];
                seen = 1;
                std::swap(nums[head], nums[i]);
                k++;
                head++;
            }
        }

        return k;
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

    std::vector<int> nums = std::vector( {1,1,1,1,3,3,3,3,5,5,5,6,7,8,8} );
    Solution sol = Solution();
    sol.removeDuplicates(nums);
    printVector(nums);
    return 0;
}

