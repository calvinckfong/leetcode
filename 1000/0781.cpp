// 781. Rabbits in Forest
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> count;
        int result = 0;
        for (auto& a: answers)
        {
            if (a>0)    count[a]++;
            else        result++;
        }

        for (auto& c: count) {
            int grp_size = c.first + 1;
            result += (c.second / grp_size) * grp_size;
            result += ((c.second % grp_size)>0) * grp_size;
        }
        return result;
    }
};
