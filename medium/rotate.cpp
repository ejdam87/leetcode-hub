#include <vector>
#include <iostream>
#include <numeric>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k)
    {

        int n = nums.size();
        if (n == 0)
        {
            return;
        }

        k %= n;
        if (k == 0)
        {
            return;
        }

        for (int i = 0; i < std::gcd(n, k); i++)
        {
            int next = nums[i];
            int current = nums[i];
            int j = (i + k) % n;
            while (j != i)
            {
                next = nums[j];
                nums[j] = current;
                current = next;
                j = (j + k) % n;
            }
            nums[j] = next;
        }
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
    Solution sol = Solution();
    std::vector<int> v = std::vector({-1,-100,3,99});
    sol.rotate(v, 2);
    printVector(v);
}
