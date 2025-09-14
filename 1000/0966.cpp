// 966. Vowel Spellchecker
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        words_perfect = set<string>();
        words_cap = map<string, string>();
        words_vow = map<string, string>();

        for (string& w: wordlist) {
            words_perfect.insert(w);
            string wLow = toLower(w);
            if (!words_cap.count(wLow)) {
                words_cap[wLow] = w;
            }

            string wLowDV = deVowel(wLow);
            if (!words_vow.count(wLowDV)) {
                words_vow[wLowDV] = w;
            }
        }

        vector<string> res(queries.size());
        int i=0;
        for (string& q: queries) {
            res[i++] = solve(q);
        }

        return res;
    }

private:
    set<string> words_perfect;
    map<string, string> words_cap;
    map<string, string> words_vow;

    string toLower(string word) {
        string res = "";
        for (char c: word) {
            res += tolower(c);
        }
        return res;
    }

    string deVowel(string word) {
        string res = "";
        for (char c: word) {
            res += (isVowel(c) ? '*' : c);
        }
        return res;
    }

    bool isVowel(char c) {
        return (c=='a') ||
            (c=='e') ||
            (c=='i') ||
            (c=='o') ||
            (c=='u');
    }

    string solve(string query) {
        if (words_perfect.count(query))
            return query;

        string qLow = toLower(query);
        if (words_cap.count(qLow))
            return words_cap[qLow];

        string qLowDV = deVowel(qLow);
        if (words_vow.count(qLowDV))
            return words_vow[qLowDV];

        return "";
    }
};
