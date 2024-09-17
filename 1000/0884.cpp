// 884. Uncommon Words from Two Sentences
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;
        tokenize(s1, words);
        tokenize(s2, words);

        vector<string> result;
        for (auto it: words) {
            if (it.second == 1)
                result.push_back(it.first);
        }

        return result;
    }

    void tokenize(string& s, unordered_map<string, int>& tokens) {
        char *start = &s[0];
        char *p = &s[0];
        for (int i=0; i<s.size(); i++, p++) {
            if (s[i] == ' ') {
                tokens[string(start, p)]++;
                start = p+1;
            }
        }
        // last token
        tokens[string(start, p)]++;
    }
};
