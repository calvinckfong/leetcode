// 1415. The k-th Lexicographical String of All Happy Strings of Length n
class Solution {
public:
    string getHappyString(int n, int k) {
        int cnt = (1 << (n-1));
        int cnt3 = 3 * cnt;
        if (k > cnt3) return "";

        k--;
        char last;
        string result(n, ' ');
        if (k < cnt) {
            last = 'a';
        } else if (k < 2*cnt) {
            last = 'b';
            k -= cnt;
        } else {
            last = 'c';
            k -= 2*cnt;
        }
        result[0] = last;

        const char lut[3][2] = {
            {'b', 'c'},
            {'a', 'c'},
            {'a', 'b'}};
        
        for (int i=1; i<n; i++) {
            last = lut[last-'a'][(k>>(n-i-1))&1];
            result[i] = last;
        }

        return result;
    }
};
