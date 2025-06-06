// 2434. Using a Robot to Print the Lexicographically Smallest String
class Solution {
public:
    string robotWithString(string s) {
        int freq[26] = {0};
        for (char& c: s) {
            freq[c-'a']++;
        }

        stack<char> stk;
        string result;
        int minC = 0;
        for (char& c: s) {
            stk.emplace(c);
            freq[c-'a']--;
            while (minC<26 && freq[minC]==0) {
                minC++;
            }
            while (!stk.empty() && stk.top()<='a'+minC) {
                result.push_back(stk.top());
                stk.pop();
            }
        }
        return result;
    }
};
