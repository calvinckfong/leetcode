// 67. Add Binary
class Solution {
public:
    string addBinary(string a, string b) {
        int pa = a.size()-1;
        int pb = b.size()-1;
        int carry = 0;
        string ret;

        while (pa>=0 || pb>=0 || carry)
        {
            if (pa>=0)
                carry += a[pa--] - '0';
            if (pb>=0)
                carry += b[pb--] - '0';
            ret = ((carry%2)?'1':'0') + ret;
            carry /= 2;
        }
        return ret;
    }
};
