// 2678. Number of Senior Citizens
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for (int i=0; i<details.size(); i++) {
            int age = (details[i][11]-'0')*10 + details[i][12] - '0';
            result+=(age>60);
        }
        return result;
    }
};
