// 3163. String Compression III
class Solution {
public:
    string compressedString(string word) {
        stringstream result;
        char last = word[0];
        int count=1, n=word.size();
        for (int i=1; i<n; i++) {
            char c = word[i];
            if (c == last) {
                if (count == 9) {
                    result << count << last;
                    count = 0;
                }
                count++;
            } else {
                result << count << last;
                last = c;
                count = 1;
            }
        }
        result << count << last;
        return result.str();
    }
};
