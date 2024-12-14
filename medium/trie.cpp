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

int main()
{
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->startsWith("app");
    delete obj;
}
