// 948. Bag of Tokens
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, l=0, r=tokens.size()-1;
        sort(tokens.begin(), tokens.end());

        while (l<=r)
        {
            if (tokens[l]>power) 
                if (score==0 || r-l<=1) break;
                else { power+=tokens[r--]; score--; }
            else
            {
                score++;
                power -= tokens[l++];
            }
        }

        return score;
    }
};
