// 58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        string t;
        stringstream ss(s);
        int len;
        while (getline(ss, t, ' '))
        {
            if (t.size())
                len = t.size();
        }
        return len;
    }
};
