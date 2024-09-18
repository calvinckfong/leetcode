// 179. Largest Number
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> str(n);

        for (int i=0; i<n; i++)
            str[i] = to_string(nums[i]);

        sort(str.begin(), str.end(), [](string& s1, string& s2){
            return s1+s2 > s2+s1;
        });

        if (str[0] == "0") return "0";

        string result;
        for (int i=0; i<n; i++)
            result += str[i];

        return result;
    }
};
