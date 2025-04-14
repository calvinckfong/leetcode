// 1534. Count Good Triplets
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), result=0;
        for (int i=0; i<n-2; i++) {
            for (int k=2; k<n; k++) {
                if (abs(arr[i]-arr[k])<=c) {
                    for (int j=i+1; j<k; j++) {
                        if (abs(arr[i]-arr[j])<=a && 
                            abs(arr[j]-arr[k])<=b) {
                                result++;
                            }
                    }
                }
            }
        }
        return result;
    }
};
