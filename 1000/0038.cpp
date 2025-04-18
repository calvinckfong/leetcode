// 38. Count and Say
class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";

        return RLE(countAndSay(n-1));
    }

    string RLE(string s) {
        auto c = s.rbegin();
        char last = *c; c++;
        int cnt = 1;
        string result="";
        
        for (; c!=s.rend(); ++c) {
            if (*c != last) {
                result = to_string(cnt) + last + result;
                last = *c;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt) {
            result = to_string(cnt) + last + result;
        }
        return result;
    }
};
