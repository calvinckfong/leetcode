// 1106. Parsing A Boolean Expression
class Solution {
public:
    enum Operation {
        NONE = 0,
        NOT,
        AND,
        OR
    };
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        Operation op = NONE;
        int val_cnt = 0;
        bool res;
        stack<pair<Operation, int>> op_stack;
        pair<Operation, int> last_op;
        stack<bool> val_stack;
        for (int i=0; i<n; i++) {
            switch (expression[i])
            {
            case '!':   op = NOT;   break;
            case '&':   op = AND;   break;
            case '|':   op = OR;    break;
            case '(':
                op_stack.push({op, val_cnt});
                val_cnt = 0;
                break;
            case ')':
                last_op = op_stack.top();
                op_stack.pop();
                op = last_op.first;
                
                if (op == NOT) {
                    res = val_stack.top(); val_stack.pop(); val_cnt--;
                    res = !res;
                } else if (op == AND) {
                    res = val_stack.top(); val_stack.pop(); val_cnt--;
                    while (val_cnt>0) {
                        bool t = val_stack.top();
                        val_stack.pop();
                        res &= t;
                        val_cnt--;
                    }
                } else if (op == OR) {
                    res = val_stack.top(); val_stack.pop(); val_cnt--;
                    while (val_cnt>0) {
                        bool t = val_stack.top();
                        val_stack.pop();
                        res |= t;
                        val_cnt--;
                    }
                }
                cout << endl;
                val_stack.push(res);
                val_cnt = last_op.second + 1;
                break;
            case 't':
                val_stack.push(true);
                val_cnt++;
                break;
            case 'f':
                val_stack.push(false);
                val_cnt++;
                break;
            default:
                break;
            }
        }
        return res;
    }
};
