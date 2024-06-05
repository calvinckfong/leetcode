// 1002. Find Common Characters
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int nWords = words.size();
        vector<vector<int>> freq(26, vector<int>(nWords, 0));

        for (int i=0; i<nWords; i++) {
            string word = words[i];
            for (char c: word) {
                freq[c-'a'][i]++;
            }
        }

        vector<string> result;
        for (int i=0; i<26; i++) {
            int n = *min_element(freq[i].begin(), freq[i].end());
            string c = {(char)('a'+i)};
            for (int j=0; j<n; j++) {
                result.push_back(c);
            }
        }
        return result;
    }
};
