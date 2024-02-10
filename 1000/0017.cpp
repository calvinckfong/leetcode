// 17. Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> digitMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        vector<string> tmp;
        for (int i=0; i<digits.size(); i++)
        {
            string c = digitMap[digits[i]-'2'];

            if (result.size()<=0)
            {
                for (int j=0; j<c.size(); j++)
                    result.push_back(string(1, c[j]));
            }
            else
            {
                tmp.clear();
                for (int k=0; k<result.size(); k++)
                {
                    for (int j=0; j<c.size(); j++)
                    {
                        tmp.push_back(result[k] + c[j]);
                    }
                }
                result.clear();
                for (string s: tmp)
                    result.push_back(s);
            }
        }
        return result;
    }
};
