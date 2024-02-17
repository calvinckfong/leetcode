// 1642. Furthest Building You Can Reach
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> q; // to store diff where bricks or ladders are required
        for (int i=0; i<n-1; i++)
        {
            int diff = heights[i+1] - heights[i];
            if (diff>0)
                // priority queue is sorted ascending.  
                // biggest step will be at the top when negated
                q.push(-diff); 

            // When q has more elements then ladders,
            // use bricks first 
            if (q.size() > ladders)
            {
                bricks += q.top(); 
                q.pop();
            }

            // no more bricks and ladders
            if (bricks < 0) return i;
        }

        // come to the end of heights
        return n-1;
    }
};
