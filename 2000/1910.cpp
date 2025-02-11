// 1910. Remove All Occurrences of a Substring
class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.size();
        int pn = part.size();

        for (int i=0; i<n; i++) {
            st.push(s[i]);

            if (st.size()>=pn && check(st, part, pn)) {
                for (int j=0; j<pn; j++) {
                    st.pop();
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }

private:
    bool check(stack<char>& st, string& part, int len) {
        stack<char> tmp = st;

        for (int i=len-1; i>=0; i--) {
            if (tmp.top() != part[i]) return false;
            tmp.pop();
        }
        return true;
    }
};
