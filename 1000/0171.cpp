// 171. Excel Sheet Column Number
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        //for (int i=0; i<columnTitle.size(); i++)
        for (auto i: columnTitle)
        {
            result = result*26 + i - 'A' + 1;
        }
        return result;
    }
};
