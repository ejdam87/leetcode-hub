
class Solution
{
private:
    int numSet(int num)
    {
        int total = 0;
        while ( num > 0 )
        {
            total += num & 1;
            num >>= 1;
        }
        return total;
    }
public:
    int minimizeXor(int num1, int num2)
    {
        int set1 = numSet( num1 );
        int set2 = numSet( num2 );

        int res = num1;
        if ( set2 >= set1 )
        {
            int diff = set2 - set1;
            int k = 0;
            while ( diff > 0 )
            {
                if ( (res & (1 << k)) == 0 )
                {
                    res |= ( 1 << k );
                    diff--;
                }
                k++;
            }
        }
        else
        {
            int diff = set1 - set2;
            int k = 0;
            while ( diff > 0 )
            {
                if ( (res & (1 << k)) > 0 )
                {
                    res &= ~(1 << k);
                    diff--;
                }
                k++;
            }
        }
        return res;
    }
};

int main()
{
    Solution().minimizeXor( 79, 74 );
}