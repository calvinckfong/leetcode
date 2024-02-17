// 168. Excel Sheet Column Title
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        do
        {
            columnNumber--;
            result += ('A' + (columnNumber%26));
            columnNumber/=26;
        } while (columnNumber);
        reverse(result.begin(), result.end());
        return result;
    }
};
