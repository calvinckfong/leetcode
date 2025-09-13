// 3541. Find Most Frequent Vowel and Consonant
class Solution {
public:
    int maxFreqSum(string s) {
        const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
        vector<int> freq(26, 0);
        int maxVowel = 0, idx;
        for (char c: s) {
            freq[c - 'a']++;
        }
        for (char c: vowels)    {
            maxVowel = max(maxVowel, freq[c-'a']);    
            freq[c-'a'] = 0;
        }
        return *max_element(freq.begin(), freq.end()) + maxVowel;
    }
};
