// 2751. Robot Collisions
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Create all robots' indices and sort according to their positions
        int n=positions.size();
        vector<int> indices;
        for (int i=0; i<n; i++)
            indices.push_back(i);
        sort(indices.begin(), indices.end(), [&](int a, int b){
            return positions[a]<positions[b];
        });

        stack<int> st;
        for (int idx: indices) {
            if (directions[idx]=='R') {
                st.push(idx);
            } else {
                // check with the robot at the top of the stack
                while (!st.empty() && healths[idx]>0) {
                    int top = st.top(); st.pop();
                    if (healths[idx] < healths[top]) { // top win
                        healths[top]--;
                        healths[idx]=0;
                        st.push(top);
                    } else if (healths[idx] > healths[top]) { // idx win
                        healths[idx]--;
                        healths[top]=0;
                    } else { // draw
                        healths[idx] = healths[top] = 0;
                    }
                }
            }
        }

        // Check robots still alive
        vector<int> result;
        for (int i=0; i<n; i++) {
            if (healths[i]>0)   result.push_back(healths[i]);
        }
        return result;
    }
};
