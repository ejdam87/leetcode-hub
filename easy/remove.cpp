#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val)
    {

        if (nums.size() == 0)
        {
            return 0;
        }

        int k = 0;
        int n = nums.size();

        int i = 0;
        int j = n - 1;

        while (i != j)
        {
            if (nums[i] == val)
            {
                std::swap(nums[i], nums[j]);
                j--;
            }
            else
            {
                i++;
                k++;
            }
        }

        if (nums[i] != val)
        {
            k++;
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

    std::vector<int> nums = std::vector( {1, 5, 4, 3, 4, 8, 1, 4} );
    int val = 4;
    Solution sol = Solution();
    sol.removeElement(nums, val);
    printVector(nums);
    return 0;
}
