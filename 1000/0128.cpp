// 128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), maxlen=0, cnt, last=-2e9;
        priority_queue<int, vector<int>, std::greater<int>> pq(nums.begin(), nums.end());
        while (n)
        {
            if (pq.top() == last)
                ;
            else if (pq.top() == last+1)
                cnt++;
            else
                cnt = 1;
            
            last = pq.top();
            pq.pop();
            maxlen = max(maxlen, cnt);
            n--;
        }
        return maxlen;
    }
};
