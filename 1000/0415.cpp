// 415. Add Strings
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int a, b, carry=0, sum;
        string result;

        while (n1>=0 || n2>=0)
        {
            a = (n1>=0)?num1[n1--]-'0':0;
            b = (n2>=0)?num2[n2--]-'0':0;
            sum = a + b + carry;
            carry = sum/10;
            result = to_string(sum%10) + result;
        }

        return (carry)?"1"+result:result;
    }
};
