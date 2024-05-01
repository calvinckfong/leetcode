// 2000. Reverse Prefix of Word
class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Solution 1
        auto p = word.find(ch);
        if (p != string::npos)
            reverse(word.begin(), word.begin()+p+1);

        return word;
        
        /* Solution 2
        for (int i=0; i<word.size(); i++) {
            if (ch == word[i]) {
                int j=0;
                while (j<i) {
                    swap(word[j++], word[i--]);
                }
                break;
            }
        }

        return word;
        */
    }
};
