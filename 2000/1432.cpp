// 1432. Max Difference You Can Get From Changing an Integer
class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string a(str), b(str);

        for (char& c: a) {
            if (c != '9') {
                replace(a, c, '9');
                break;
            }
        }

        for (int i=0; i<b.size(); i++) {
            char c = b[i];
            if (i==0 && c != '1') {
                replace(b, c, '1');
                break;
            } else if (c != '0' && c != b[0]) {
                replace(b, c, '0');
                break;
            }
        }
        return stol(a) - stol(b);
    }

private:
    void replace(string& s, char x, char y) {
        for (char& c : s) {
            if (c == x) c = y;
        }
    }
};
