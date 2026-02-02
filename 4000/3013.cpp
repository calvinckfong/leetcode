// 3013. Divide an Array Into Subarrays With Minimum Cost II
class Container {
public:
    Container(int k) : _k(k), _sum(0) {}
    
    void add(int x) {
        if (!st2.empty() && x>=*(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            _sum += x;
        }
        adjust();
    } 

    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it);
            _sum -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    long long sum() { return _sum; }

private:
    int _k;
    long long _sum;
    multiset<int> st1, st2;

    void adjust() {
        while (st1.size()<_k && st2.size()>0) {
            int x = *(st2.begin());
            st1.emplace(x);
            _sum += x;
            st2.erase(st2.begin());
        }
        while (st1.size()>_k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            _sum -= x;
        }
    }
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        Container cnt(k-2);
        for (int i=1; i<k-1; i++)
            cnt.add(nums[i]);

        long long res = cnt.sum() + nums[k-1];
        for (int i=k; i<n; i++) {
            int j = i-dist-1;
            if (j>0) cnt.erase(nums[j]);
            cnt.add(nums[i-1]);
            res = min(res, cnt.sum() + nums[i]);
        }

        return res + nums[0];
    }
};
