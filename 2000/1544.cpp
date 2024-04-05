// 1544. Make The String Great
class Solution {
public:
    string makeGood(string s) {
        if (s.size()<2) return s;
        
        stack<char> st;
        for (char c: s) {
            if (!st.empty()) {
                char f = st.top();
                if (abs(f-c) == 32)
                    st.pop();
                else
                    st.push(c);
            } else {
                st.push(c);
            }
        }

        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
