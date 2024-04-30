// 224. Basic Calculator
class Solution {
public:
    int calculate(string s) {
        long result=0, curr=0, sign=1;
        stack<int> nums, ops;

        for (char c: s) {
            if (isdigit(c)) {
                curr = curr*10 + c-'0';
            } else {
                result += sign * curr;
                curr = 0;
                switch(c) {
                case '+':
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
                case '(':
                    nums.push(result);
                    ops.push(sign);
                    result = 0;
                    sign = 1;
                    break;
                case ')':
                    result = ops.top() * result + nums.top();
                    ops.pop();
                    nums.pop();
                    break;
                default:
                    break;
                }
            }
        }
        return result + sign * curr;
    }
};
