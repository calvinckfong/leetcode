// 933. Number of Recent Calls
class RecentCounter {
public:
    deque<int> requests;
    RecentCounter() {
        requests.clear();
    }
    
    int ping(int t) {
        requests.push_back(t);

        while (requests.front()<t-3000)
        {
            requests.pop_front();
        }

        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
