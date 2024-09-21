// 386. Lexicographical Numbers
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for (int i=1; i<=min(n, 9); i++) {
            result.push_back(i);
            addWithPrefix(result, i, n);
        }

        return result;
    }

    void addWithPrefix(vector<int>& result, int prefix, int maxVal) {
        if (prefix >= maxVal) return;

        int start = prefix*10;
        int end = min(maxVal, start+9);
        for (int i=start; i<=end; i++) 
        {
            result.push_back(i);
            addWithPrefix(result, i, maxVal);
        }
    }
};
