// 1518. Water Bottles
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0, empty = 0;
        while (numBottles) {
            // accumulate full bottles
            result += numBottles;
            // accumuate empty bottles
            empty += numBottles;
            // exchange empty bottles to full
            numBottles = empty/numExchange;
            // remaining empty bottles
            empty = empty%numExchange;
        }
        return result;
    }
};
