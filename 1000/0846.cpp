// 846. Hand of Straights
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize) return false;

        map<int, int> freq;
        for (int v: hand) {
            freq[v]++;
        }
        int cnt=0, curr;
        while (!freq.empty()) {
            if (cnt==0) {
                curr = freq.begin()->first;
            } else if (freq[++curr]==0) 
                return false;

            freq[curr]--;
            if (freq[curr]==0) freq.erase(curr);
            cnt = ++cnt%groupSize;
        }
        return true;
    }
};
