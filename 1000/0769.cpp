// 769. Max Chunks To Make Sorted
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        for (int i=0; i<n; i++) {
            if (st.empty() || arr[i]>st.top()) {
                st.push(arr[i]);
            } else {
                int top = st.top();
                while (!st.empty() && arr[i]<st.top()) {
                    st.pop();
                }
                st.push(top);
            }
        }
        return st.size();
    }
};
