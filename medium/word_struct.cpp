#include <string>
#include <unordered_map>
#include <memory>

class TrieNode
{
public:
    char c;
    std::unordered_map< char, std::unique_ptr<TrieNode> > data = {};
    bool end = false;
    TrieNode(char cc) : c(cc) {}
};

class WordDictionary
{

private:
    std::unordered_map< char, std::unique_ptr<TrieNode> > roots = {};

    bool _search(std::string word, TrieNode* current, int i)
    {
        if ( i == word.length() )
        {
            return current == nullptr ? false : current -> end;
        }

        auto& succs = i == 0 ? roots : current -> data;
        if ( word[i] != '.' )
        {
            if ( !succs.contains( word[i] ) )
            {
                return false;
            }

            return _search( word, succs[ word[i] ].get(), i + 1 );
        }
        else
        {
            for ( auto& [k, v] : succs )
            {
                if ( _search( word, v.get(), i + 1 ) )
                {
                    return true;
                }
            }
            return false;
        }
    }

public:

    WordDictionary(){}

    void addWord(std::string word)
    {

        if ( roots.size() == 0 || !roots.contains( word[0] ) )
        {
            roots[ word[0] ] = std::make_unique<TrieNode>( word[0] );
        }

        TrieNode* current = roots[word[0]].get();
        if ( 1 == word.length() )
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
        return _search( word, nullptr, 0 );
    }
};
