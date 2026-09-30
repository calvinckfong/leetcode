// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        for (int i=0; i<seq.size(); i++) {
            res.push_back(i&1 ^ (seq[i]=='('));
        }
        return res;
    }
};
