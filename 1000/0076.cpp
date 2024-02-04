// 76. Minimum Window Substring
class Solution {
public:
    unordered_map<char, int> t_map;

    bool AddChar(char c, unordered_map<char, int> &s_map)
    {
        s_map[c]++;
        // printf("Add %c %d\n", c, s_map[c]);
        for (auto it=t_map.begin(); it!=t_map.end(); ++it)
        {   
            // printf("Chk %c %d %d\n", it->first, it->second, s_map[it->first]);
            if (it->second > s_map[it->first]) return false;
        }
        return true;
    }

    bool PopChar(char c, unordered_map<char, int> &s_map)
    {
        s_map[c]--;
        // printf("Pop %c %d\n", c, s_map[c]);
        for (auto it=t_map.begin(); it!=t_map.end(); ++it)
        {   
            // printf("Chk %c %d %d\n", it->first, it->second, s_map[it->first]);
            if (it->second > s_map[it->first]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s==t)   return t;

        for (int i=0; i<t.size(); i++)
            t_map[t[i]]++;

        // Hint 1
        int l=0, r=0;
        int best_l, best_r;
        // Hint 2
        int n=s.size();
        unordered_map<char, int> s_map;
        bool containAll = false;
        while (r<n)
        {
            if (containAll = AddChar(s[r++], s_map)) break;
        }
        // Unable to fit t even for whole s
        if (!containAll)    return "";
        best_l=0; best_r=r;

        // Hint 3
        while (l<n)
        {
            if (!containAll && r<n)
            {
                // move right pointer
                containAll = AddChar(s[r++], s_map);
            }
            else if (l<r)
            {
                // move left pointer
                containAll = PopChar(s[l++], s_map);
            }
            else if (r==n && n-l<t.size())
            {
                break;
            }

            // keep substring if shorter
            if (containAll && (r-l)<(best_r-best_l))
            {
                best_l=l; best_r=r;
            }
        }

        return s.substr(best_l, best_r-best_l);
    }
};
