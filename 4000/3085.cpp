// 3085. Minimum Deletions to Make String K-Special
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char& c: word) freq[c]++;

        int result = word.size();
        for (auto& [_, fi]: freq) {
            int del = 0;
            for (auto& [_, fj]: freq) {
                if (fi>fj) {
                    del += fj;
                } else if (fj > fi + k) {
                    del += fj - (fi + k);
                }
            }
            result = min(result, del);
        }
        return result;
    }
};
