// 1291. Sequential Digits
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;

        for (int i=2; i<9+1; i++)
        {
            int candidate=0, step=0;
            for (int j=0; j<i; j++)
            {
                candidate = candidate*10 + j + 1;
                step = step*10+1;
            }

            while (candidate % 10 != 0)
            {
                if (candidate>=low && candidate<=high)
                    ret.push_back(candidate);
                candidate+=step;
            }
        }

        return ret;
    }
};
