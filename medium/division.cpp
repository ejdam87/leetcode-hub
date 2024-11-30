#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:

    double path(std::vector<std::vector<std::string>>& equations,
                std::vector<double>& values,
                std::string from,
                std::string to,
                std::unordered_set<std::string>& visited)
    {
        if (from == to)
        {
            return 1;
        }

        for (int i = 0; i < equations.size(); i++)
        {
            auto& eq = equations[i];
            if (eq[0] == from && !visited.contains(eq[1]))
            {
                visited.insert( eq[1] );
                double val = path(equations, values, eq[1], to, visited);

                if (val != -1)
                {
                    return values[i] * val;
                }
            }

            if (eq[1] == from && !visited.contains(eq[0]))
            {
                visited.insert( eq[0] );
                double val = path(equations, values, eq[0], to, visited);

                if (val != -1)
                {
                    return (1 / values[i]) * val;
                }
            }

        }

        return -1;
    }

    double evalQuery(std::vector<std::vector<std::string>>& equations,
                     std::vector<double>& values,
                     std::vector<std::string>& query)
    {
        std::unordered_set<std::string> visited = {};
        return path(equations, values, query[0], query[1], visited);
    }

public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
                                     std::vector<double>& values,
                                     std::vector<std::vector<std::string>>& queries)
    {
        std::unordered_set< std::string > vars = {};
 
        for ( auto& eq : equations )
        {
            for ( auto& s : eq )
            {
                vars.insert( s );
            }
        }

        std::vector<double> res = {};
        for ( auto& query : queries )
        {
            if ( !vars.contains( query[0] ) || !vars.contains( query[1] ) )
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back( evalQuery(equations, values, query) );
            }
        }

        return res;
    }
};
