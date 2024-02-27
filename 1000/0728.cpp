// 728. Self Dividing Numbers
class Solution {
public:
    bool isSelfDividing(int num)
    {
        int cpy = num, digit;
        while (cpy)
        {
            digit = cpy%10;
            if (digit==0) return false;
            if (num%digit != 0) return false;
            cpy/=10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int i=left; i<=right; i++)
        {
            if (isSelfDividing(i))
                result.push_back(i);
        }
        return result;
    }
};
