// 2566. Maximum Difference by Remapping a Digit
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.size();
        string minV=s, maxV=s;
        char minC = s[0], maxC='9';
        for (char& c: s) {
            if (c != '9') {
                maxC = c;
                break;
            }
        }

        for (int i=0; i<n; i++) {
            if (minV[i]==minC) minV[i] = '0';
            if (maxV[i]==maxC) maxV[i] = '9';
        }

        return stoi(maxV) - stoi(minV);
    }
};
