// 916. Word Subsets
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(), n2 = words2.size();
        vector<map<char, int>> hist1(n1);
        map<char, int> hist2;
        for (int i=0; i<n1; i++)
            hist1[i] = getHist(words1[i]);
        for (int i=0; i<n2; i++) {
            map<char, int> hist = getHist(words2[i]);
            for (auto p: hist) {
                hist2[p.first] = max(hist2[p.first], hist[p.first]);
            }
        }

        vector<string> result;
        for (int i=0; i<n1; i++) {
            map<char, int> hist = hist1[i];
            bool isSubset = true;
            
            for (auto p: hist2) {
                if (hist[p.first] < p.second) {
                    isSubset = false;
                    break;
                }
            }
            
            if (isSubset) result.push_back(words1[i]);
        }
        return result;
    }

private:
    map<char, int> getHist(string word) {
        map<char, int> hist;
        for (char c: word) {
            hist[c]++;
        }
        return hist;
    }
};
