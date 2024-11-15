// 1574. Shortest Subarray to be Removed to Make Array Sorted
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l, r, n=arr.size();;
        for (r=n-1; r>0 && arr[r]>=arr[r-1]; r--) ;

        int result = r;
        for (l=0; l<r; l++) {
            if (l>0 && arr[l-1]>arr[l]) break;
            while (r<n && arr[l]>arr[r])
                r++;
            result = min(result, r-l-1);
        }
        return result;
    }
};
