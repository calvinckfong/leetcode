// 881. Boats to Save People
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), [](int a, int b){return a>b;});
        int result=0, h=0, t=people.size()-1, curr;
        
        while (h<t) {
            result++;
            curr = people[h++];
            if (curr+people[h]<=limit) {
                h++;
            } else if (curr+people[t]<=limit) {
                t--;
            } 
        }
        // last boat
        if (h==t) result++; 
        return result;
    }
};
