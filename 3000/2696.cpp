// 2696. Minimum String Length After Removing Substrings
class Solution {
public:
    int minLength(string& s) {
        int n = s.size();
        if (n >= 2) {
            auto it1 = s.find("AB");
            if (it1 != string::npos)
                return minLength(s.erase(it1, 2));
            
            auto it2 = s.find("CD");
            if (it2 != string::npos)
                return minLength(s.erase(it2, 2));
        }
        return n;
    }
};
