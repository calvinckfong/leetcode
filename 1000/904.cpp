// 904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, n=fruits.size();
        int seen[100001]={0}, cnt=0, res=0;
        while (r<n) {
            if (seen[fruits[r]]==0) cnt++;
            seen[fruits[r]]++;
            if (cnt>2) {
                if (--seen[fruits[l]] == 0)
                    cnt--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
