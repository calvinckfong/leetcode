// 135. Candy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1, result=n;

        while (i<n)
        {
            if (ratings[i] == ratings[i-1]) 
            {
                i++;
                continue;
            }

            // rising
            int peak = 0;
            while (i<n && ratings[i] > ratings[i-1]) {
                peak++;
                i++;
                result += peak; 
            }

            // falling
            int valley = 0;
            while (i<n && ratings[i] < ratings[i-1]) {
                valley++;
                i++;
                result += valley;
            }
            result -= min(peak, valley);
        }
        return result;
    }
};
