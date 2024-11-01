// 1957. Delete Characters to Make Fancy String
class Solution {
public:
    string makeFancyString(string s) {
        char last = 0;
        int count = 0;
        string result = "";
        for (char c: s) {
            if (c != last) {
                last = c;
                count = 1;
                result += c;
            } else {
                count ++;
                if (count<3) result += c;
            }
        }
        return result;
    }
};
