// 860. Lemonade Change
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int notes[2] = {0};
        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                notes[0]++;
            } else if (bills[i] == 10) {
                if (notes[0]==0) return false;
                notes[0]--;
                notes[1]++;
            } else {
                if (notes[0]>0 && notes[1]>0) {
                    notes[0]--;
                    notes[1]--;
                } else if (notes[0]>=3) {
                    notes[0] -= 3;
                } else return false;
            }
        }
        return true;
    }
};
