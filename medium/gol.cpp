#include <vector>

class Solution {
private:
    int alive_count(std::vector<std::vector<int>>& board, int i, int j)
    {
        int c = 0;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                if (di == 0 && dj == 0)
                {
                    continue;
                }

                int ni = i + di;
                int nj = j + dj;

                if (ni < 0 || ni >= board.size())
                {
                    continue;
                }

                if (nj < 0 || nj >= board[0].size())
                {
                    continue;
                }

                c += board[ni][nj];

            }
        }

        return c;
    }

public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        std::vector<std::vector<int>> nxt = {};

        for (int i = 0; i < board.size(); i++)
        {
            std::vector<int> nxt_row = {};
            for (int j = 0; j < board[0].size(); j++)
            {
                int ac = alive_count(board, i, j);
                if ( (board[i][j] == 1 && (ac < 2 || ac > 3)) || ( board[i][j] == 0  && ac != 3) )
                {
                    nxt_row.push_back(0);
                }
                else
                {
                    nxt_row.push_back(1);
                }
            }

            nxt.push_back(nxt_row);
        }

        board = nxt;
    }
};