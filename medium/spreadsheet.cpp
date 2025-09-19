#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    size_t start = 0, end = 0;

    while ((end = s.find(delim, start)) != std::string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + 1;
    }

    result.push_back(s.substr(start));
    return result;
}

class Spreadsheet {
private:
    std::vector<std::vector<int>> grid;

    std::pair<int, int> get_coords(const std::string& cell)
    {
        int col = cell[0] - 'A';
        int row = std::stoi( cell.substr(1) ) - 1;
        return {row, col};
    }

    int parse(const std::string& token)
    {
        if (std::all_of(token.begin(), token.end(), [](unsigned char c){ return std::isdigit(c); }))
        {
            return std::stoi(token);
        }
        else
        {
            auto [row, col] = get_coords(token);
            return grid[row][col];
        }
    }

public:
    Spreadsheet(int rows)
    {
        grid = std::vector<std::vector<int>>(rows, std::vector<int>(26, 0));
    }

    void setCell(std::string cell, int value)
    {
        auto [row, col] = get_coords(cell);
        grid[row][col] = value;
    }

    void resetCell(std::string cell)
    {
        setCell(cell, 0);
    }

    int getValue(std::string formula) 
    {
        auto tokens = split(formula.substr(1), '+');
        if (tokens.size() < 2)
        {
            return -1;
        }

        auto a = tokens[0];
        auto b = tokens[1];
        return parse(a) + parse(b);
    }
};


int main()
{
    auto s = Spreadsheet(24);
}
