// 726. Number of Atoms
class Solution {
public:
    typedef map<string, int> AtomCnt;
    typedef struct Group {
        AtomCnt group_map;
        int multiplier;
        Group(int m) { multiplier=m; }
    } Group;
    string countOfAtoms(string formula) {
        int n = formula.size();
        AtomCnt finalAtomCnt;
        stack<Group> atomCntStack;
        
        // reverse parsing, start from end of string
        int multiplier = 1;
        for (int i=n-1; i>=0; i--) {
            char c = formula[i];
            if (isdigit(c)) {
                string multi_str = string() + c;
                while (i>0 && isdigit(formula[i-1])) {
                    multi_str = formula[--i] + multi_str;
                }
                multiplier = stoi(multi_str);
                continue;
            }

            if (c == ')') {
                atomCntStack.push(Group(multiplier));
                multiplier = 1;
                continue;
            }

            if (c == '(') {
                AtomCnt src = atomCntStack.top().group_map;
                int group_multiplier =  atomCntStack.top().multiplier;
                atomCntStack.pop();
                AtomCnt& target = atomCntStack.empty() ?
                    finalAtomCnt : atomCntStack.top().group_map;
                for (auto item: src) {
                    target[item.first] += item.second * group_multiplier;
                }
                continue;
            }

            if (isalpha(c)) {
                string atom_str = string() + c;
                while (isalpha(c) && !isupper(c)) {
                    c = formula[--i];
                    atom_str = c + atom_str;
                }
                AtomCnt& target = atomCntStack.empty() ? 
                    finalAtomCnt : atomCntStack.top().group_map;
                target[atom_str] += multiplier;
                multiplier = 1;
            }
        }

        // construct output string
        string result;
        for (auto item: finalAtomCnt) {
            result += item.first;
            result += (item.second>1)?to_string(item.second):"";
        }
        return result;
    }
};
