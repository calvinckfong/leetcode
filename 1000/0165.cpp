// 165. Compare Version Numbers
class Solution {
public:
    vector<string> tokenize(string& str) {
        vector<string> result;
        int l, r;
        for (l=0, r=0; r<str.size(); r++) {
            if (str[r]=='.') {
                result.push_back(str.substr(l, r-l));
                l=r+1;
            }
        }
        result.push_back(str.substr(l, r-l));
        return result;
    }

    int compareVersion(string version1, string version2) {
        vector<string> tokens1 = tokenize(version1);
        vector<string> tokens2 = tokenize(version2);

        int i=0;
        while (i<tokens1.size() || i<tokens2.size()) {
            int v1=0, v2=0;
            if (i<tokens1.size()) v1=stoi(tokens1[i]);
            if (i<tokens2.size()) v2=stoi(tokens2[i]);
            if (v1<v2) return -1;
            else if (v2<v1) return 1;
            i++;
        }

        return 0;
    }
};
