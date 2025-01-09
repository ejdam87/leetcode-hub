#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <algorithm>
#include <unordered_set>

class TrieNode
{
public:
    char c;
    std::unordered_map< char, std::unique_ptr<TrieNode> > data = {};
    bool end = false;
    TrieNode(char cc) : c(cc) {}
};

class Trie
{
private:
    std::unordered_map< char, std::unique_ptr<TrieNode> > roots = {};

    bool _search(std::string word, bool full)
    {
        if (roots.size() == 0 || !roots.contains(word[0]))
        {
            return false;
        }

        TrieNode* current = roots[word[0]].get();

        int i = 0;
        while (i < word.length() - 1)
        {
            if ( !current -> data.contains( word[i + 1] ) )
            {
                return false;
            }

            current = current -> data[ word[i + 1] ].get();
            i++;
        }

        if (full)
        {
            return current -> end;
        }

        return true;
    }

public:
    Trie(){}

    void insert(std::string word)
    {

        if ( roots.size() == 0 || !roots.contains( word[0] ) )
        {
            roots[ word[0] ] = std::make_unique<TrieNode>( word[0] );
        }

        TrieNode* current = roots[word[0]].get();
        if ( 1 == word.length())
        {
            current -> end = true;
        }

        int i = 1;
        while (i < word.length())
        {
            if ( !current -> data.contains( word[i] ) )
            {
                current -> data[ word[i] ] = std::make_unique<TrieNode>( word[i] );
            }

            current = current -> data[ word[i] ].get();
            if ( i == word.length() - 1 )
            {
                current -> end = true;
            }
            i++;
        }
    }

    bool search(std::string word)
    {
        return _search( word, true );
    }

    bool startsWith(std::string prefix)
    {
        return _search( prefix, false );
    }
};

class Solution
{
private:

    Trie trie;

    void existsOn(
            std::vector<std::vector<char>>& board,
            int i,
            int j,
            std::string current,
            std::unordered_set<std::string>& words,
            std::vector< std::pair<int, int> >& path,
            int max_len,
            std::vector<std::string>& res
        )
    {
        if ( !trie.startsWith( current ) )
        {
            return;
        }
        if ( words.contains(current) )
        {
            words.erase( current );
            trie = {};
            for ( auto& word : words )
            {
                trie.insert( word );
            }
            res.push_back( current );
        }
        else if ( current.length() >= max_len )
        {
            return;
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

                std::pair<int, int> vertex = {ni, nj};
                if ( std::find( path.begin(), path.end(), vertex ) == path.end() )
                {
                    path.push_back( {ni, nj} );
                    existsOn( board, ni, nj, current + board[ni][nj], words, path, max_len, res );
                    path.pop_back();
                }
            }
        }
    }

    bool exist(
        std::vector<std::vector<char>>& board,
        std::unordered_set<std::string>& words,
        int max_len,
        std::vector<std::string>& res)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                std::vector< std::pair<int, int> > path = { {i, j} };
                existsOn(board, i, j, {board[i][j]}, words, path, max_len, res);
            }
        }

        return false;
    }
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
    {
        std::vector< std::string > res = {};
        size_t max_len = 0;
        for ( auto& word : words )
        {
            max_len = std::max( max_len, word.length() );
            trie.insert( word );
        }

        std::unordered_set< std::string > ws(words.begin(), words.end());
        exist( board, ws, max_len, res );
        return res;
    }
};
