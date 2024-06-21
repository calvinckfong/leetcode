// 1052. Grumpy Bookstore Owner
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size(), grumpy_sum=0;
        if (minutes==n) 
            return accumulate(customers.begin(), customers.end(), 0);

        for (int i=0; i<n; i++)
            grumpy_sum += (1-grumpy[i]) * customers[i];

        int maxValue=0;
        for (int i=0; i<n-minutes+1; i++) {
            int value=0;
            for (int j=i; j<i+minutes; j++) {
                value += grumpy[j]*customers[j];
            }
            maxValue = max(maxValue, value);
        }
        return grumpy_sum+maxValue;
    }
};
