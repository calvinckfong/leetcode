// 3321. Find X-Sum of All K-Long Subarrays II
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res(n-k+1);
        maxSize = x;

        freq.reserve(n);

        for (int i=0; i<k; i++)
            insert(nums[i]);
        res[0] = currSum;

        for (int l=1, r=k; r<n; l++, r++) {
            remove(nums[l-1]);
            insert(nums[r]);
            res[l] = currSum;
        }

        return res;
    }

private:
    int maxSize = 0;
    long long currSum = 0;
    unordered_map<int, int> freq;
    set<pair<int, int>, greater<pair<int, int>>> top, rest;

    void insert(int v) {
        int& f = freq[v];
        if (f>0) {
            auto it = top.find({f, v});
            if (it != top.end()) {
                top.erase(it);
                currSum -= (long long)f * v;
            }
            else
                rest.erase({f,v});
        }

        top.insert({++f, v});
        currSum += (long long)f * v;

        if (top.size()>maxSize) {
            auto it = prev(top.end());
            currSum -= (long long)it->first * it->second;
            rest.insert(*it);
            top.erase(it);
        }
    }

    void remove(int v) {
        int& f = freq[v];
        if (f==0) return;

        auto it = top.find({f,v});
        if (it!=top.end()) {
            top.erase(it);
            currSum -= (long long)f * v;
        }
        else 
            rest.erase({f,v});

        if (--f == 0)
            freq.erase(v);
        else
            rest.insert({f, v});

        if (top.size() < maxSize && !rest.empty()) {
            auto it = rest.begin();
            currSum += (long long)it->first * it->second;
            top.insert(*it);
            rest.erase(it);
        } 
    }
};
