// 2818. Apply Operations to Maximize Score
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n);

        for (int i=0; i<n; i++) {
            int num = nums[i];

            for (int f=2; f<=sqrt(num); f++) {
                if (num % f == 0) {
                    scores[i]++;
                    while (num%f == 0)  num /= f;
                }
            }
            if (num>=2) scores[i]++;
        }

        vector<int> next(n, n);
        vector<int> prev(n, -1);
        stack<int> stack;
        for (int i=0; i<n; i++) {
            while (!stack.empty() && 
                    scores[stack.top()] < scores[i]) {
                int topIdx = stack.top();
                stack.pop();
                next[topIdx] = i;
            }

            if (!stack.empty())
                prev[i] = stack.top();
            
            stack.push(i);
        }

        vector<long long> arrayLen(n);
        for (int i=0; i<n; i++) {
            arrayLen[i] = (long long)(next[i] - i) * (i - prev[i]);
        }

        priority_queue<pair<int, int>> pq;
        for (int i=0; i<n; i++)
            pq.push({nums[i], i});

        long long score = 1;
        while (k>0) {
            auto [num, i] = pq.top();
            pq.pop();

            long long op = min((long long)k, arrayLen[i]);
            score = (score * power(num, op) % MOD);
            k -= op;
        }

        return score;
    }

private:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp%2)  res = (res*base) % MOD;
            base = (base*base) % MOD;
            exp /= 2;
        }
        return res;
    }
};
