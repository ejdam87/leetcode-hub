#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>


class Solution
{
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank)
    {
        std::queue< std::pair<std::string, int> > q;
        q.push( {startGene, 0} );
        char bases[] = {'A', 'C', 'T', 'G'};

        while (!q.empty())
        {
            auto [gene, m] = q.front();
            q.pop();

            if (m > 8)
            {
                return -1;
            }

            if (std::find(bank.begin(), bank.end(), gene) == bank.end() && gene != startGene)
            {
                continue;
            }

            if (gene == endGene)
            {
                return m;
            }

            for (int pos = 0; pos < 8; pos++)
            {
                char prev = gene[pos];
                for (int bi = 0; bi < 4; bi++)
                {
                    if (bases[bi] == prev)
                    {
                        continue;
                    }

                    gene[pos] = bases[bi];
                    q.push( {gene, m + 1} );
                }
                gene[pos] = prev;
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<std::string> b = {"AACCGGTA"};
    std::cout << Solution().minMutation( "AACCGGTT", "AACCGGTA", b ) << '\n';
}
