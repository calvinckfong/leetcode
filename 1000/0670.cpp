// 670. Maximum Swap
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        int lastSeen[10] = {-1};

        for (int i=0; i<n; i++)
            lastSeen[str[i]-'0'] = i;

        for (int i=0; i<n; i++) {
            for (int j=9; j>str[i]-'0'; j--) {
                if (lastSeen[j]>i) {
                    swap(str[i], str[lastSeen[j]]);
                    return atoi(str.c_str());
                }
            }
        }
        return num;
    }
};
