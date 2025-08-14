// 2264. Largest 3-Same-Digit Number in String
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char maxChar = '0'-1;

        for (int i=2; i<n; i++) {
            if (num[i]==num[i-1] && num[i]==num[i-2]) {
                maxChar = max(maxChar, num[i]);
            }
        }

        if (maxChar>='0') {
            return string(3, maxChar);
        }
        return "";
    }
};
