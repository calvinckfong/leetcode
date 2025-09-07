// 1304. Find N Unique Integers Sum up to Zero
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n, 0);
        for (int i=0; i<n/2; i++)
        {
            res[i*2] = i+1;
            res[i*2+1] = -i-1;
        }
        return res;
    }
};
