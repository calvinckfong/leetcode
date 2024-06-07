// 648. Replace Words
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string result="", tok;
        while (getline(ss, tok, ' ')) {
            result += lookup(dictionary, tok) + " ";
        }
        result.pop_back();
        return result;
    }

private:
    string lookup(vector<string>& dictionary, string token) {
        string ret = token;
        int tn=token.size(), wn, i;
        bool found;
        for (string w: dictionary) {
            wn = w.size();
            if (tn<wn) continue;
            if (token.substr(0, wn) == w) return w;
        }

        return token;
    }
};
