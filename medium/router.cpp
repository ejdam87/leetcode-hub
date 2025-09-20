#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Router {
private:
    deque<long long> q = deque<long long>();
    unordered_map<long long, vector<int>> present = unordered_map<long long, vector<int>>();
    unordered_map<int, deque<int>> dest_times = unordered_map<int, deque<int>>();
    int limit;
public:
    Router(int memoryLimit) : limit(memoryLimit) {}

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        long long code = encode(source, destination, timestamp);
        if ( !present.contains( code ) || present[code].size() == 0 )
        {
            q.push_back(code);
            present[ code ] = {source, destination, timestamp};

            if ( !dest_times.contains( destination ) )
            {
                dest_times[destination] = deque<int>();
            }
            dest_times[destination].push_back( timestamp );

            if (q.size() > limit)
            {
                forwardPacket();
            }

            return true;
        }
        return false;
    }

    vector<int> forwardPacket()
    {
        if (q.size() == 0)
        {
            return {};
        }

        long long code = q.front();
        auto v = present[code];
        present[code] = {};
        q.pop_front();
        dest_times[v[1]].pop_front();
        return v;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        auto times = dest_times[destination];
        auto lower = lower_bound(times.begin(), times.end(), startTime);
        auto upper = upper_bound(times.begin(), times.end(), endTime);
        return upper - lower;
    }
};

int main()
{
    Router obj = Router(3);
    bool param_1 = obj.addPacket(1,2,3);
    param_1 = obj.addPacket(1,3,3);
    vector<int> param_2 = obj.forwardPacket();
}
