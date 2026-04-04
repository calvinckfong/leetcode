// 2075. Decode the Slanted Ciphertext
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows==1) return encodedText;

        int n = encodedText.size(), cols = n/rows;
        string res;
        res.reserve(n);

        for (int c=0; c<cols; c++) {
            int r=0, k=c;
            for (int r=0; r<rows && k<cols; k++, r++) {
                res += encodedText[r*cols + k];
            }
        }

        while (!res.empty() && res.back()==' ') {
            res.pop_back();
        }

        return res;
    }
};
