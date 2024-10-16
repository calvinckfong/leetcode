// 1405. Longest Happy String
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string result;
        // iterate for at least 2 items
        while (pq.size()>1) {
            pair<int,char> i = pq.top();
            pq.pop();
            pair<int,char> j = pq.top();
            pq.pop();

            if (i.first>=2) {
                result += i.second;
                result += i.second;
                i.first-=2;
            } else if (i.first==1) {
                result += i.second;
                i.first--;
            }

            if (j.first>=i.first && j.first>=2) {
                result += j.second;
                result += j.second;
                j.first-=2;
            } else {
                result += j.second;
                j.first--;
            }

            if (i.first>0) pq.push(i);
            if (j.first>0) pq.push(j);
        }

        // Clean up remaining
        if (pq.empty()) return result;
        pair<int, char> i = pq.top();
        if (i.first>=2) {
            result += i.second;
            result += i.second;
        } else {
            result += i.second;
        }
        return result;
    }
};
