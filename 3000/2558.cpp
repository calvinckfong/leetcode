// 2558. Take Gifts From the Richest Pile
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while (k-->0) {
            int g = pq.top();
            pq.pop();
            pq.push(sqrt(g));
        }

        long long result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};
