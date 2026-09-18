// 1520. Maximum Number of Non-Overlapping Substrings
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<Seg> seg(26, (Seg){-1, -1});
        for (int i=0; i<s.size(); i++) {
            int idx = s[i] - 'a';
            if (seg[idx].left == -1) {
                seg[idx].left = seg[idx].right = i;
            } else {
                seg[idx].right = i;
            }
        }

        for (int i=0; i<26; i++) {
            if (seg[i].left != -1) {
                for (int j=seg[i].left; j<=seg[i].right; j++) {
                    int idx = s[j] - 'a';
                    if (seg[i].left <= seg[idx].left &&
                            seg[idx].right <= seg[i].right) {
                        continue;    
                    }
                    seg[i].left = min(seg[i].left, seg[idx].left);
                    seg[i].right = max(seg[i].right, seg[idx].right);
                    j = seg[i].left;
                }
            }
        }

        sort(seg.begin(), seg.end());
        vector<string> res;
        int end = -1;
        for (auto& ss: seg) {
            int l = ss.left, r = ss.right;
            if (l == -1) continue;
            if (end == -1 || l>end) {
                end = r;
                res.emplace_back(s.substr(l, r-l+1));
            }
        }
        return res;
    }

private:
    struct Seg {
        int left, right;
        bool operator< (const Seg& rhs) const {
            if (right == rhs.right) {
                return left > rhs.left;
            }
            return right < rhs.right;
        }
    };
};
