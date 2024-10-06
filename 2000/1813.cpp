// 1813. Sentence Similarity III
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> tokens1 = tokenize(sentence1);
        vector<string> tokens2 = tokenize(sentence2);

        if (tokens1.size() > tokens2.size())
            return similar(tokens1, tokens2);
        else
            return similar(tokens2, tokens1);
    }

private:
    vector<string> tokenize(string& s) {
        vector<string> result;
        string w;
        stringstream ss(s);
        while (ss >> w) result.push_back(w);
        return result;
    }

    bool similar(vector<string>& t1, vector<string>& t2)
    {
        // end1>=end2
        int start=0, end1=t1.size()-1, end2=t2.size()-1;
        while (start<end2+1 && t1[start] == t2[start])
            start++;
        
        while (end2>=0 && t1[end1] == t2[end2]) {
            end1--;
            end2--;
        }
        return end2<start;
    }
};
