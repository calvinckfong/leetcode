// 752. Open the Lock
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //unordered_set<string> visited;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        int result = 0;
        queue<string> q;
        q.push(target);
        visited.insert(target);

        // Try to reduce target down to "0000"
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                string curr = q.front();
                q.pop();

                if (curr == "0000") return result;

                // loop through all digits
                string next;
                for (int d=0; d<4; d++) {
                    // increasing
                    next = curr;
                    next[d] = (next[d]=='9') ? next[d]='0' : next[d]+1;
                    if (visited.find(next) == visited.end()) { 
                        visited.insert(next);
                        q.push(next);
                    }

                    // decreasing
                    next = curr;
                    next[d] = (next[d]=='0') ? next[d]='9' : next[d]-1;
                    if (visited.find(next) == visited.end()) { 
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};
