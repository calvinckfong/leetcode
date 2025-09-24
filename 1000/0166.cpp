// 166. Fraction to Recurring Decimal
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long absNum = labs(numerator);
        long absDen = labs(denominator);

        if (absNum==0) return "0";
        
        string res = to_string(absNum/absDen);
        long rem = absNum % absDen;

        if (rem != 0)
        {
            unordered_map<long, int> rem_cnt;
            res += ".";
            while (rem != 0) {
                if (rem_cnt.count(rem)) {
                    res.insert(rem_cnt[rem], "(");
                    res += ")";
                    break;
                }
                rem_cnt[rem] = res.size();
                rem *= 10;
                res += to_string(rem/absDen);
                rem = rem % absDen;
            }
        }

        if ((numerator<0) ^ (denominator<0)) res = "-" + res;
        return res;
    }
};
