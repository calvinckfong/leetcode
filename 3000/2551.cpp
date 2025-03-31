// 2551. Put Marbles in Bags
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairWeights(n-1);
        for (int i=0; i<n-1; i++)
            pairWeights[i] = weights[i] + weights[i+1];

        sort(pairWeights.begin(), pairWeights.end());

        long long result = 0;
        for (int i=0; i<k-1; i++)
            result += pairWeights[n-i-2] - pairWeights[i];

        return result;
    }
};
