// 2071. Maximum Number of Tasks You Can Assign
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int nT = tasks.size(), nW = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l=1, r=min(nT, nW);
        int result = 0;
        while (l<=r) {
            int mid = (l+r)/2;
            if (Valid(mid, pills, strength, tasks, workers)) {
                result = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return result;
    }

private:
    bool Valid(int mid, int pills, int strength, vector<int>& tasks, vector<int>& workers) {
        int p = pills, nW=workers.size();
        multiset<int> ws;
        for (int i=nW-mid; i<nW; i++) {
            ws.insert(workers[i]);
        }

        for (int i=mid-1; i>=0; i--) {
            if (auto it=prev(ws.end()); *it>=tasks[i]) {
                ws.erase(it);
            } else {
                if (!p) return false;
                
                auto rep = ws.lower_bound(tasks[i] - strength);
                if (rep == ws.end()) return false;
                p--;
                ws.erase(rep);
            }
        }
        return true;
    }
};
