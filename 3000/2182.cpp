// 2182. Construct String With Repeat Limit
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        priority_queue<char> pq;
        for (char c: s) {
            if (freq[c-'a']==0) pq.push(c);
            freq[c-'a']++;
        }

        s.clear();
        while (!pq.empty()) {
            int c = pq.top()-'a';
            pq.pop();
            int nAppend = min(freq[c], repeatLimit);
            s.append(nAppend, c+'a');
            freq[c] -= nAppend;

            if (freq[c]>0 && !pq.empty()) {
                char nextC = pq.top()-'a';
                pq.pop();
                s.push_back(nextC+'a');
                freq[nextC]--;
                if (freq[nextC]>0) pq.push(nextC+'a');

                pq.push(c+'a');
            }
        }
        return s;
    }
};
