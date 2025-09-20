// 3508. Implement Router
class Router {
public:
    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        packet_t packet = {source, destination, timestamp};
        
        if (cache.count(packet)) return false;

        if (q.size() == maxSize) {
            packet_t p = q.front();
            cache.erase(p);
            stk[p[1]]++;
            q.pop();
        }

        q.push(packet);
        cache[packet]++;
        timestamps[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        packet_t res = q.front();
        q.pop();
        cache.erase(res);
        stk[res[1]]++;
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (timestamps.count(destination) == 0) return 0;
        packet_t& p = timestamps[destination];
        int t = stk[destination];
        auto l = lower_bound(p.begin()+t, p.end(), startTime);
        auto u = upper_bound(p.begin()+t, p.end(), endTime);
        return (int)(u-l);
    }

private:
    typedef vector<int> packet_t;

    int maxSize = 0;
    map<packet_t, int> cache;
    queue<packet_t> q;
    unordered_map<int, packet_t> timestamps;
    unordered_map<int, int> stk;
};
