// 2053. Kth Distinct String in an Array
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        vector<string> vec;
        for (int i=0; i<arr.size(); i++) {
            freq[arr[i]]++;
            if (freq[arr[i]]==1) vec.push_back(arr[i]);
        }

        for (auto str: vec) {
            if (freq[str] == 1) {
                if (--k == 0) return str;
            }
        }
        return string("");
    }
};
