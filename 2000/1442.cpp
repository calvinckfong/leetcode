// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(), result=0;

        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                int a=arr[i];
                for (int u=i+1; u<j; u++)
                    a = a ^ arr[u];
                
                for (int k=j; k<n; k++) {
                    int b=arr[j];
                    for (int u=j+1; u<=k; u++)
                        b = b ^ arr[u];
                    
                    result += (a==b); 
                }
            }
        }

        return result;
    }
};
