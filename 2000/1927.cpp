// 1927. Sum Game
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        auto [n0, q0] = get(num.substr(0, n/2));
        auto [n1, q1] = get(num.substr(n/2, n/2));
        return ((q0+q1)%2==1) || (n0-n1 != (q1-q0)*9/2);
    }

private:
    pair<int, int> get(string&& s) {
        int n=0, q=0;
        for (char& c: s) {
            if (c=='?') {
                q++;
            } else {
                n += (c-'0');
            }
        }
        return {n, q};
    }
};
