// 383. Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hist[26] = {0};

        for (int i=0; i<magazine.size(); i++)
        {
            hist[magazine[i]-'a']++;
        }
        
        for (int i=0; i<ransomNote.size(); i++)
        {
            if (hist[ransomNote[i]-'a']>0)
                hist[ransomNote[i]-'a']--;
            else
                return false;
        }

        return true;
    }
};
