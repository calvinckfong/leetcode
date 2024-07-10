// 1598. Crawler Log Folder
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (int i=0; i<logs.size(); i++) {
            if (logs[i] == "../")
                result = max(0, result-1);
            else if (logs[i] != "./")
                result++;
        }
        return result;
    }
};
