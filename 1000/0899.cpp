// 899. Orderly Queue
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k>1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        else
        {
            string result = s;
            for (int i=0; i<s.size()-1; i++)
            {
                s.push_back(s[0]);
                s.erase(0, 1);
                if (s<result) result = s;
            }
            return result;
        }
    }
};
