// 2452. Words Within Two Edits of Dictionary
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int i, cnt;
        for (string q: queries)
        {
            for (string d: dictionary)
            {
                cnt = 0;
                for (i=0; i<q.size(); i++)
                {
                    cnt += (q[i]!=d[i]);
                    if (cnt>2) break;
                }
                if (cnt<=2)
                {
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;

    }
};
