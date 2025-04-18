// 38. Count and Say
class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";

        string str = countAndSay(n-1), result="";
        int len = str.size();
        char last = str[len-1];
        int cnt = 1;
        for (int i=len-2; i>=0; i--) {
            if (str[i] == last) {
                cnt++;
            } else {
                result = to_string(cnt) + last + result;
                last = str[i];
                cnt = 1;
            }
        }
        return to_string(cnt) + last + result;
    }
};
