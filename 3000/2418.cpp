// 2418. Sort the People
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> height_name_list(n);
        for (int i=0; i<n; i++) {
            height_name_list[i] = {heights[i], names[i]};
        }
        sort(height_name_list.rbegin(), height_name_list.rend());

        vector<string> result(n);
        for (int i=0; i<n; i++) {
            result[i] = height_name_list[i].second;
        }
        return result;
    }
};
