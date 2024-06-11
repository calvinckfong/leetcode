// 1122. Relative Sort Array
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        vector<int> result;
        sort(arr1.begin(), arr1.end());
        for (int k: arr2) {
            while (true) {
                auto it = find(arr1.begin(), arr1.end(), k);
                if (it == arr1.end()) break;
                result.push_back(*it);
                arr1.erase(it);
            }
        }
        for (int k: arr1) result.push_back(k);
        return result;
    }
};
