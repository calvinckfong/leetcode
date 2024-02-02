// 739. Daily Temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n);
        deque<int> q;
 
        for (int i=n-1; i>=0; i--)
        {
            if (q.empty())
            {
                q.push_front(i);
            }
            else
            {
                while (!q.empty() && temperatures[i]>=temperatures[q.front()])
                {
                    q.pop_front();
                }

                if (!q.empty())
                    ret[i] = q.front() - i;

                q.push_front(i);
            }
        }

        for (int i=0; i<n; i++)
        {
            if (!ret[i])
            {
                for (int j=1; j<n-i; j++)
                {
                    if (temperatures[i+j] > temperatures[i])
                    {
                        ret[i] = j;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
