// 1726. Tuple with Same Product
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> products(n*(n-1)/2);
        int idx = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                products[idx++] = nums[i] * nums[j];
            }
        }
        sort(products.begin(), products.end());

        int result = 0, last_prod=-1, same_prod_cnt=0;
        for (int p: products) {
            if (p==last_prod) {
                same_prod_cnt++;
            } else {
                result += 8*(same_prod_cnt-1)*same_prod_cnt/2;
                same_prod_cnt = 1;
                last_prod = p;
            }
        }
        return result;
    }
};
