// 3433. Count Mentions Per User
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> count(numberOfUsers);
        vector<int> next_online_time(numberOfUsers);
        sort(events.begin(), events.end(), 
            [&](const vector<string>& a, const vector<string>& b){
                int a_t = stoi(a[1]);
                int b_t = stoi(b[1]);
                if (a_t != b_t) return a_t < b_t;
                if (b[0] == "OFFLINE") return false;
                return true;
            });
        
        for (auto&& e: events) {
            int t = stoi(e[1]);
            if (e[0] == "MESSAGE") {
                if (e[2] == "ALL") {
                    for (int i=0; i<numberOfUsers; i++) count[i]++;
                } else if (e[2] == "HERE") {
                    for (int i=0; i<numberOfUsers; i++) {
                        if (next_online_time[i] <= t) {
                            count[i]++;
                        }
                    }
                } else {
                    int idx = 0;
                    for (int i=0; i<e[2].size(); i++) {
                        if (isdigit(e[2][i])) {
                            idx = idx * 10 + (e[2][i] - '0');
                        }
                        if (i+1 == e[2].size() || e[2][i+1] == ' ') {
                            count[idx]++;
                            idx = 0;
                        }
                    }
                }
            } else {
                int idx = stoi(e[2]);
                next_online_time[idx] = t + 60;
            }
        }

        return count;
    }
};
