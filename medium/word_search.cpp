#include <vector>
#include <string>
#include <utility>
#include <algorithm>


class Solution
{
private:
    bool existsOn(
            std::vector<std::vector<char>>& board,
            int i,
            int j,
            std::string current,
            std::string& word,
            std::vector< std::pair<int, int> >& path
        )
    {
        if (current == word)
        {
            return true;
        }
        else if ( current.length() ==  word.length())
        {
            return false;
        }

        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if ( (di != 0 && dj != 0) || (di == 0 && dj == 0) )
                {
                    continue;
                }

                int ni = i + di;
                int nj = j + dj;

                if (ni < 0 || ni >= board.size() || nj < 0 || nj >= board[0].size())
                {
                    continue;
                }

                if ( word[ current.length() ] != board[ni][nj] )
                {
                    continue;
                }

                std::pair<int, int> vertex = {ni, nj};
                if ( std::find( path.begin(), path.end(), vertex ) == path.end() )
                {
                    path.push_back( {ni, nj} );
                    if (existsOn( board, ni, nj, current + board[ni][nj], word, path ) )
                    {
                        return true;
                    }
                    path.pop_back();
                }
            }
        }

        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                std::vector< std::pair<int, int> > path = { {i, j} };
                if ( existsOn(board, i, j, {board[i][j]}, word, path) )
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    std::vector< std::vector<char> > board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "ABCCED";
    Solution().exist( board, word );
}
