// 567. Permutation in String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int n1 = s1.size();
        int map1[26], map2[26];
        for (int i=0; i<n1; i++) {
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }

        for (int i=0; i<s2.size()-n1; i++) {
            if (map_match(map1, map2)) return true;
            // sliding window
            map2[s2[i+n1]-'a']++;
            map2[s2[i]   -'a']--;
        }
        return map_match(map1, map2);
    }

private:
    bool map_match(int map1[26], int map2[26]) {
        for (int i=0; i<26; i++)
            if (map1[i] != map2[i]) return false;
        return true;
    }
};
