// 2342. Max Sum of a Pair With Equal Sum of Digits
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        priority_queue<int, vector<int>, greater<int>> digitSumList[82];

        for (int num: nums) {
            int digitSum = getDigitSum(num);
            digitSumList[digitSum].push(num);
            if (digitSumList[digitSum].size()>2)
                digitSumList[digitSum].pop();
        }

        int result = -1;
        for (auto& q: digitSumList) {
            if (q.size() == 2) {
                int sum = q.top();
                q.pop();
                sum += q.top();
                result = max(result, sum); 
            }
        }

        return result;
    }

private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n>0) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
};
