// 1103. Distribute Candies to People
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int i=0;
        while (candies)
        {
            int n = min(i+1, candies);
            result[(i%num_people)] += n;
            candies -= n;
            i++;
        }
        return result;
    }
};
