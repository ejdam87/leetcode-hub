#include <iostream>

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {

        int shift = 0;

        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        int optimizedResult = left << shift;
        return optimizedResult;
    }
};

int main()
{
    std::cout << Solution().rangeBitwiseAnd(1073741832, 2147483647) << '\n';
}
