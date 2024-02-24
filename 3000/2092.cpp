// 2092. Find All People With Secret
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // sort meetings according to time
        sort(meetings.begin(), meetings.end(), [](vector<int>a, vector<int>b){
            //return a[2]<b[2];
            if (a[2]<b[2]) return true;
            else if (a[2]>b[2]) return false;
            else return ( min(a[0], a[1])<min(b[0], b[1]) );
        });

        // Initialize with person 0 and first person
        vector<unordered_set<int>> sessions = {{}};
        unordered_set<int> result = {0, firstPerson};
        
        int currTime = 0;
        for (auto m: meetings)
        {
            if (m[2]>currTime) // new meeting
            {
                for (auto s: sessions)
                {
                    for (auto p: s)
                    {
                        // check if any one in current meeting has the secret
                        // if true, add all persons in this session to result
                        if (result.find(p) != result.end())
                        {
                            result.insert(s.begin(), s.end());
                            break;
                        }
                    }
                }
                sessions.clear();
                sessions = {{}};
                currTime = m[2];
            }

            bool hasSecret = false;
            for (auto &s: sessions)
            {
                if ( s.find(m[0])!=s.end()  || s.find(m[1])!=s.end() )
                {
                    s.insert(m[0]);
                    s.insert(m[1]);
                    hasSecret = true;
                    break;
                }
            }
            if (!hasSecret) // new session
                sessions.push_back({m[0], m[1]});
        }
        // finalize last meeting
        for (auto s: sessions)
        {
            for (auto p: s)
            {
                // check if any one in current meeting has the secret
                if (result.find(p) != result.end())
                {
                    result.insert(s.begin(), s.end());
                    break;
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
