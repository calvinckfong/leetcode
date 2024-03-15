// 3074. Apple Redistribution into Boxes
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for (int i=0; i<apple.size(); i++) sum+=apple[i];
        sort(capacity.rbegin(), capacity.rend());

        int m=0;
        while (m<capacity.size())
        {
            sum -= capacity[m++];
            if (sum<=0) return m;
        }
        return capacity.size();
    }
};
