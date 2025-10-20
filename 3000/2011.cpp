// 2011. Final Value of Variable After Performing Operations
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (string& op: operations) {
            if (op=="++X" || op=="X++") res++;
            else if (op=="--X" || op=="X--") res--;
        }
        return res;
    }
};
