// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(), result=0;

        // Using the property that 
        // if a[i] ^ a[i+1] ^ ... ^ a[k] = 0,
        // there are k-i combinations that 
        // a[i] ^ ... ^ a[j-1] = a[j] ^ ... ^ a[k]
        for (int i=0; i<n-1; i++) {
            int a = 0;
            for (int k=i; k<n; k++) {
                a^=arr[k];
                if (a == 0) result += (k-i); 
            }
        }

        return result;
    }
};
