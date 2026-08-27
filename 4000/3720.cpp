// 3720. Lexicographically Smallest Permutation Greater Than Target
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        freq = vector<int>(26);
        for (int i=0; i<n; i++) {
            freq[s[i]-'a']++;
            freq[target[i]-'a']--;
        }

        for (int i=n-1; i>=0; i--) {
            int t = target[i] - 'a';
            freq[t]++;
            if (*min_element(freq.begin(), freq.end()) < 0) {
                continue;
            }

            for (int j=t+1; j<26; j++) {
                if (freq[j]) {
                    freq[j]--;
                    target[i] = 'a' + j;
                    target.resize(i+1);
                    return target + getMinString();
                }
            }
        }

        return "";
    }

private:
    vector<int> freq;
    string getMinString() {
        string res;
        for (int i=0; i<26; i++) {
            res.append(freq[i], 'a'+i);
        }
        return res;
    }
};
