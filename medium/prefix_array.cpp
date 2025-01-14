#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B)
    {
        std::unordered_set< int > aset;
        std::unordered_set< int > bset;
        std::unordered_set< int > intersect;
        std::vector< int > C;
        for (int i = 0; i < A.size(); i++)
        {
            aset.insert( A[i] );
            bset.insert( B[i] );

            if ( aset.contains( B[i] ) )
            {
                intersect.insert( B[i] );
            }
            if ( bset.contains( A[i] ) )
            {
                intersect.insert( A[i] );
            }

            C.push_back( intersect.size() );

        }

        return C;
    }
};
