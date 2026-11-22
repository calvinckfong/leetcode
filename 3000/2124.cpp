// 2124. Check if All A's Appears Before All B's
class Solution {
public:
    bool checkString(string s) {
        int posa = s.find_last_of('a');
        if (posa != string::npos)
        {
            int posb = s.find('b');
            return (posb==string::npos || posa<posb);
        }
        return true;
    }
};
