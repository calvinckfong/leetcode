// 1481. Least Number of Unique Integers after K 
class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int, int>&b) {
        return a.second<b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // fill arr to freq to count the frequency of numbers
        map<int, int> freq;
        for (auto &it: arr)
            freq[it]++;
        int n = freq.size();
        
        // copy freq to vector m for sorting by frequency
        vector<pair<int,int>> m;
        for (auto &it: freq)
            m.push_back(it);
        sort(m.begin(), m.end(), cmp);

        // remove the numbers starting the lowest frequency
        int i;
        for (i=0; i<n, k>0; i++)
        {
            k -= m[i].second;
        }
        return n-i+(k<0);
    }
};
