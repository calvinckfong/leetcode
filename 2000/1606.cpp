// 1606. Find Servers That Handled Most Number of Requests
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> handled(k);
        vector<int> turns(k);
        iota(turns.begin(), turns.end(), 0);

        MinHeap<int> free(greater<>{}, std::move(turns));
        MinHeap<Job> busy;

        for (int i=0; i<ssize(arrival); i++) {
            while (!busy.empty() && busy.top().at <= arrival[i]) {
                int x = busy.top().server;
                busy.pop();
                free.push(i+(x-i%k+k)%k);
            }

            if (free.empty()) continue;
            int x = free.top() % k;
            free.pop();
            busy.push({arrival[i] + load[i], x});
            handled[x]++;
        }

        int maxV = ranges::max(handled);
        vector<int> res;
        for (int i=0; i<k; i++) {
            if (handled[i] == maxV) res.push_back(i);
        }
        return res;
    }

private:
    struct Job {
        int at;
        int server;
        auto operator<=>(const Job&) const = default;
    };

    template<class T> using MinHeap = priority_queue<T, vector<T>, greater<>>;
};
