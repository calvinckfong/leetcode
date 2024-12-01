// 1346. Check If N and Its Double Exist
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int& a, int& b){
            return abs(a) < abs(b);
        });
        int n = arr.size();

        for (int i=0; i<n; i++) {
            int doubled = arr[i]*2;
            for (int j=i+1; j<n && abs(arr[j])<=abs(doubled); j++) {
                if (arr[j] == doubled) return true;
            }
        }
        return false;
    }
};
