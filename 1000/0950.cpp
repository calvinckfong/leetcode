// 950. Reveal Cards In Increasing Order
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), std::greater());
        deque<int> dq;

        for (int i=0; i<deck.size(); i++)
        {
            if (!dq.empty()) {
                int b = dq.back(); dq.pop_back();
                dq.push_front(b);
            }
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
