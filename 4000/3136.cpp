// 3136. Valid Word
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool hasVowel=false, hasConsonant=false;
        for (char& c: word) {
            if (isalpha(c)) {
                bool v = isVowel(c);
                hasVowel |= v;
                hasConsonant |= (!v);
            } else if (c < '0' || c > '9') {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }

private:
    bool isVowel(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
};
