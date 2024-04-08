// 1700. Number of Students Unable to Eat Lunch
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size(), ones=0, zeros=0;
        queue<int> q;
        for (int s: students) 
        {
            if (s) ones++;
            else zeros++;
            q.push(s);
        }
        
        int curr = 0;
        while (!q.empty())
        {
            if (ones==0 && sandwiches[curr]==1) break;
            if (zeros==0 && sandwiches[curr]==0) break;

            int s = q.front(); q.pop();
            if (s != sandwiches[curr]) {
                q.push(s);
            }
            else
            {
                curr++;
                if (curr==n) return 0;  // all sandwiches are delivered

                if (s) ones--;
                else zeros--;
            }
        }

        return q.size();
    }
};
