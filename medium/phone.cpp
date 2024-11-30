#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
private:
    void combRec( std::string digits, int i, std::string current, std::vector<std::string>& res )
    {
        if (i == digits.size())
        {
            res.push_back(current);
            return;
        }

        for (char c : mapping[digits[i]])
        {
            combRec( digits, i + 1, current + c, res );
        }
    }

public:
    std::unordered_map<char, std::string> mapping = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.length() == 0)
        {
            return {};
        }

        std::vector<std::string> res = {};
        combRec(digits, 0, "", res);
        return res;
    }
};
