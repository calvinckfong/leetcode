// 3170. Lexicographically Minimum String After Removing Stars
class Solution {
public:
    string clearStars(string s) {
        int n = s.size(), pos=0;
        stack<int> cnt[26];
        for (char& c: s) {
            if (c != '*') {
                cnt[c-'a'].push(pos);
            } else {
                for (int i=0; i<26; i++) {
                    if (!cnt[i].empty()) {
                        s[cnt[i].top()] = '*';
                        cnt[i].pop();
                        break;
                    }
                }
            }
            pos++;
        }

        string result;
        result.reserve(n);
        for (char& c: s) {
            if (c != '*')   result.push_back(c);
        }
        return result;
    }
};
