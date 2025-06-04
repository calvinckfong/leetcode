// 3403. Find the Lexicographically Largest String From the Box I
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends==1) return word;

        n = word.size();
        string last = lastString(word);
        int m = last.size();
        return last.substr(0, min(m, n-numFriends+1));
    }

private:
    int n;
    string lastString(string word) {
        int i=0, j=1;
        while (j<n) {
            int k=0;
            while (j+k<n && word[i+k]==word[j+k]) {
                k++;
            }
            if (j+k<n && word[i+k]<word[j+k]) {
                int t = i;
                i = j;
                j = max(j+1, t+k+1);
            } else {
                j += (k+1);
            }
        }
        return word.substr(i, n-i);
    }
};
