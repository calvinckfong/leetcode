// 2785. Sort Vowels in a String
class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        int i=0;
        for (char c: s) {
            if (isVowel(c)) {
                vowels.push_back(c);
                s[i] = '.';
            }
            i++;
        }
        sort(vowels.begin(), vowels.end());

        i = 0;
        for (char& c: s) {
            if (c == '.') {
                c = vowels[i++];
            }
        }
        return s;
    }

private:
    bool isVowel(char c) {
        switch (c) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
};
