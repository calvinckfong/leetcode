// 3120. Count the Number of Special Characters I
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq[26+32] = {0}, result=0;
        
        for (char w: word) freq[w-'A']++;

        for (int i=0; i<26; i++)
            result += (freq[i]>0 && freq[i+32]>0);
        return result;
    }
};
