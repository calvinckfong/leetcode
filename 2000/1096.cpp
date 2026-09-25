// 1096. Brace Expansion II
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        for (int i=0; i<expression.size(); i++) {
            const char curr = expression[i];
            if (curr == ',') {
                while (op.size() && op.back()=='*') {
                    operation();
                }
                op.push_back('+');
            } else if (curr == '{') {
                if (i>0) {
                    const char prev = expression[i-1];
                    if (prev=='}' || isalpha(prev)) op.push_back('*');
                }
                op.push_back('{');
            } else if (curr == '}') {
                while (!op.empty() && op.back()!='{') {
                    operation();
                }
                op.pop_back();
            } else {
                if (i>0) {
                    const char prev = expression[i-1];
                    if (prev=='}' || isalpha(prev)) op.push_back('*');
                }
                stk.push_back({string(1, curr)});
            }
        }

        while (!op.empty()) {
            operation();
        }
        return {stk.back().begin(), stk.back().end()};
    }

private:
    vector<char> op;
    vector<set<string>> stk;
    void operation() {
        int l = stk.size() - 2;
        int r = stk.size() - 1;
        if (op.back() == '+') {
            stk[l].merge(stk[r]);
        } else {
            set<string> tmp;
            for (auto& left: stk[l]) {
                for (auto& right: stk[r]) {
                    tmp.insert(left + right);
                }
            }
            stk[l] = move(tmp);
        }
        op.pop_back();
        stk.pop_back();
    }
};
