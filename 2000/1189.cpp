// 1189. Maximum Number of Balloons
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for (int i=0; i<text.size(); i++)
            freq[text[i]]++;

        int max_balloon = min({freq['b'], freq['a'], freq['n']});
        max_balloon = min({max_balloon, freq['l']/2, freq['o']/2});
        return max_balloon;
    }
};
