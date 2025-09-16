// 2197. Replace Non-Coprime Numbers in Array
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (int& n: nums) {
            res.push_back(n);
            while (res.size()>1) {
                int i = res.back();   
                res.pop_back();
                int j = res.back();
                res.pop_back();
                long long g = gcd(i, j);

                if (g>1) {
                    int l = 1LL*i/g*j;
                    res.push_back(l);
                } else {
                    res.push_back(j);
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
