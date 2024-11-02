// 2490. Circular Sentence
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size(), cnt=0;
        if (sentence[0] == ' ' || sentence[n-1] == ' ') return false;
        if (sentence[0] == sentence[n-1]) {
            for (int i=0; i<n; i++) {
                char c = sentence[i];
                if (c == ' ') {
                    if (sentence[i-1] != sentence[i+1])
                        return false;
                    cnt++;
                } else {
                    cnt = 0;
                }
                if (cnt>1) return false;
            }
            return true;
        }
        return false;
    }
};
