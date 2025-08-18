// 679. 24 Game
class Solution {
public:
    struct frac{
        int num, den;
    };

    bool judgePoint24(vector<int>& cards) {
        vector<frac> nums;
        for (int c: cards)
            nums.push_back({c, 1});
        return dfs(nums);
    }

private:
    bool dfs(vector<frac> nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0].num == 24*nums[0].den;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {

                vector<frac> next;
                next.reserve(n);
                for (int k=0; k<n; k++) {
                    if (k!=i && k!=j)
                        next.push_back(nums[k]);
                }

                for (auto v: compute(nums[i], nums[j])) {
                    next.push_back(v);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<frac> compute(frac a, frac b) {
        int anbn = a.num*b.num;
        int anbd = a.num*b.den;
        int adbn = a.den*b.num;
        int adbd = a.den*b.den;
        vector<frac> res(4);
        res[0] = {anbd + adbn, adbd};
        res[1] = {anbd - adbn, adbd};
        res[2] = {adbn - anbd, adbd};
        res[3] = {anbn, adbd};
        if (anbd) res.push_back({adbn, anbd});
        if (adbn) res.push_back({anbd, adbn});
        return res;
    }
};
