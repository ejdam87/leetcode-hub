#include <vector>
#include <set>
#include <utility>

class Solution {
private:
    void exploreComponent(std::vector<std::vector<char>>& grid,
                          int i,
                          int j,
                          std::set<std::pair<int, int>>& visited)
    {
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (di == 0 || dj == 0)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size())
                    {
                        continue;
                    }

                    if ( grid[ni][nj] != 'O' )
                    {
                        continue;
                    }

                    if ( visited.find( {ni, nj} ) == visited.end() )
                    {
                        visited.insert( {ni, nj} );
                        exploreComponent( grid, ni, nj, visited );
                    }
                }
            }
        }
    }

public:
    void solve(std::vector<std::vector<char>>& board)
    {

        std::set< std::pair<int, int> > visited = {};
        std::vector<int> iborder = {0, static_cast<int>(board.size() - 1)};
        std::vector<int> jborder = {0, static_cast<int>(board[0].size() - 1)};

        for (int i = 0; i < board.size(); i++)
        {
            for (int j : jborder)
            {
                if ( board[i][j] == 'O' && visited.find( {i, j} ) == visited.end())
                {
                    visited.insert( {i, j} );
                    exploreComponent(board, i, j, visited);
                }
            }
        }

        for (int j = 0; j < board[0].size(); j++)
        {
            for (int i : iborder)
            {
                if ( board[i][j] == 'O' && visited.find( {i, j} ) == visited.end())
                {
                    visited.insert( {i, j} );
                    exploreComponent(board, i, j, visited);
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O' && visited.find( {i, j} ) == visited.end())
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
