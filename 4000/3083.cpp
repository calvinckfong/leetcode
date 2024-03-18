// 3083. Existence of a Substring in a String and Its Reverse
class Solution {
public:
    bool isSubstringPresent(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        for (int i=0; i<s.size()-1; i++)
        {
            string ss = s.substr(i, 2);
            int found = rev.find(ss);
            if (found != string::npos)
                return true;
        }

        return false;
    }
};
