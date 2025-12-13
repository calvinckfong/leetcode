// 3606. Coupon Code Validator
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> res;
        vector<pair<string, string>> valid;
        int n = code.size();

        for (int i=0; i<n; i++) {
            if (!isActive[i]) continue;
            if (code[i].size()==0) continue;
            if (businessLine[i]!="electronics" && businessLine[i]!="grocery" &&
                businessLine[i]!="pharmacy" && businessLine[i]!="restaurant") continue;
            bool isValid = true;
            for (char c: code[i]) {
                if (c>='a' && c<='z') continue;
                if (c>='A' && c<='Z') continue;
                if (c>='0' && c<='9') continue;
                isValid = (c=='_');
            }
            if (isValid) valid.push_back({businessLine[i], code[i]});
        }

        sort(valid.begin(), valid.end());

        for (auto& c: valid) {
            res.push_back(c.second);
        }

        return res;
    }
};
