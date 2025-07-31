// 898. Bitwise ORs of Subarrays
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        int n = arr.size();

        for (int i=0; i<n; i++) {
            int x = arr[i];
            res.insert(x);

            for (int j=i-1, y=0; j>=0; j--) {
                x |= arr[j];
                y |= arr[j];
                res.insert(x);
                if (x==y) break;
            }
        }
        
        return res.size();
    }
};
