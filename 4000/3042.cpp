// 3042. Count Prefix and Suffix Pairs I
class Solution {
public:
    inline bool isPrefixAndSuffix(string& str1, string& str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        if (n1>n2) return false;
        for (int i=0; i<n1; i++)
        {
            // Prefix check
            if (str1[i] != str2[i] ||
                str1[i] != str2[n2-n1+i]) return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int result = 0;
        for (int i=0; i<words.size(); i++)
            for (int j=i+1; j<words.size(); j++)
                result += isPrefixAndSuffix(words[i], words[j]);
        return result;
    }
};
