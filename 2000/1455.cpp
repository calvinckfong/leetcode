// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int m = searchWord.size(), nToken=0, i;
        stringstream ss(sentence);
        string token;

        while (ss >> token) {
            nToken++;
            for (i=0; i<m; i++) {
                if (searchWord[i] != token[i]) break;
            }
            if (i==m) return nToken;
        }
        return -1;
    }
};
