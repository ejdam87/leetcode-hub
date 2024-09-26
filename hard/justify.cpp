#include <vector>
#include <string>
#include <iostream>

class Solution
{

private:
    int fitCount(int from, std::vector< std::string >& words, int maxWidth)
    {
        int total = 0;
        int total_size = 0;

        for (int i = from; i < words.size(); i++)
        {
            int spaces = total > 0 ? total : 0;
            int l = words[i].length();
            if (total_size + l + spaces <= maxWidth)
            {
                total++;
                total_size += l;
            }
            else
            {
                break;
            }
        }

        return total;
    }

    std::string distributeSpaces(int from, int to, std::vector< std::string >& words, int maxWidth)
    {
        std::string res = {};
        int total = 0;
        for (int i = from; i < to; i++)
        {
            total += words[i].length();
        }
        int spaces = maxWidth - total;
        int gaps = (to - from) - 1;
        int d = spaces / gaps;
        int r = spaces % gaps;

        std::vector<int> gap_spaces = std::vector(gaps, d);
        for (int i = 0; i < r; i++)
        {
            gap_spaces[i]++;
        }

        for (int i = from; i < to; i++)
        {
            res += words[i];
            if (i != to - 1)
            {
                res += std::string(gap_spaces[i - from], ' ');
            }
        }

        return res;
    }

    std::string leftAlign(int from, int to, std::vector< std::string >& words, int maxWidth)
    {
        std::string res = {};

        for (int i = from; i < to; i++)
        {
            res += words[i];
            if (i != to - 1)
            {
                res.push_back(' ');
            }
        }

        res += std::string(maxWidth - res.length(), ' ');

        return res;
    }

public:
    std::vector< std::string > fullJustify(std::vector< std::string >& words, int maxWidth)
    {
        int n = words.size();
        int i = 0;
        std::vector< std::string> res = {};

        while (i < n)
        {
            int count = fitCount(i, words, maxWidth);
            int j = i + count;
            std::string justfied = count == 1 || j >= n ? leftAlign(i, j, words, maxWidth) : distributeSpaces(i, j, words, maxWidth);
            res.push_back( justfied );
            i = j;
        }

        return res;
    }
};

void print_text(std::vector< std::string > rows)
{
    for (std::string row : rows)
    {
        std::cout << '"' << row << '"' << '\n';
    }
}

int main()
{
    Solution sol = Solution();
    std::vector< std::string > words = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
    int maxWidth = 20;
    std::vector< std::string > res = sol.fullJustify(words, maxWidth);
    print_text(res);
}
