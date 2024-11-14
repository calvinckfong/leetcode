// 2064. Minimized Maximum of Products Distributed to Any Store
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxVal = *max_element(quantities.begin(), quantities.end());
        if (quantities.size() == n) 
            return maxVal;

        long long l = 1, r = maxVal;
        while (l<r) {
            long long mid = (l+r)/2;
            if (distribute(quantities, mid) > n)
                l = mid+1;
            else
                r = mid;
        }

        return l;
    }

private:
    int distribute(vector<int>& quantities, int v) {
        int result = 0;
        for (auto q: quantities) {
            result += (q + v - 1)/v;
        }
        return result;
    }
};
