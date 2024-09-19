// 241. Different Ways to Add Parentheses
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n));

        return solve(expression, 0, n-1);
    }

private:
    vector<vector<vector<int>>> dp;

    vector<int> solve(string expression, int start, int end) {
        if (!dp[start][end].empty()) return dp[start][end];

        vector<int> result;

        if (start == end) {
            result.push_back(expression[start]-'0');
            return result;
        }

        if (end == start+1 && isdigit(expression[start])) {
            int val = (expression[start] - '0') * 10;
            val += expression[end] - '0';
            result.push_back(val);
            return result;
        }

        for (int i=start; i<=end; i++) {
            char op = expression[i];
            if (isdigit(op)) continue;

            vector<int> lhs = solve(expression, start, i-1);
            vector<int> rhs = solve(expression, i+1, end);

            for (int lval : lhs) {
                for (int rval: rhs) {
                    switch (op) {
                    case '+':
                        result.push_back(lval + rval);
                        break;
                    case '-':
                        result.push_back(lval - rval);
                        break;
                    case '*':
                        result.push_back(lval * rval);
                        break;
                    }
                }
            }
        }

        dp[start][end] = result;

        return result;
    }
};
