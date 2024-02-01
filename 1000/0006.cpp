// 6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;

        vector<string> rows(numRows);
        int inc = 1, idx=0;
        for (int i=0; i<s.size(); i++)
        {
            rows[idx].push_back(s[i]);
            idx += inc;
            if (idx>=numRows-1) inc = -1;
            else if (idx==0) inc = 1;
        }
        string ret;
        for (int i=0; i<numRows; i++)
            ret += rows[i];
        return ret;
    }
};
