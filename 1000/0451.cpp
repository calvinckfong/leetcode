// 451. Sort Characters By Frequency
class Solution {
public:
    string frequencySort(string s) {
        // accumulate string to map
        map<char, int> freq;
        for (auto it: s)
            freq[it]++;
        
        // copy map to vector for sorting
        vector<pair<char, int>> sorted_freq;
        for (auto &it: freq)
            sorted_freq.push_back(it);

        sort(sorted_freq.begin(), sorted_freq.end(), 
            [](pair<char, int> a, pair<char, int> b) {
                if (a.second == b.second)
                    return a.first<b.first;
                else
                    return a.second>b.second;
            });

        // output string
        string result;
        for (auto it: sorted_freq)
            for (int i=0; i<it.second; i++)
                result += it.first;
        return result;
    }
};
