// 1622. Fancy Sequence
class Fancy {
public:
    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }
    
    void append(int val) {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }
    
    void addAll(int inc) {
        b.back() = (b.back() + inc) % MOD;
    }
    
    void multAll(int m) {
        a.back() = (static_cast<long long>(a.back()) * m) % MOD;
        b.back() = (static_cast<long long>(b.back()) * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        long long a0 = static_cast<long long>(inv(a[idx])) * a.back() % MOD;
        int b0 = (b.back() - (static_cast<long long>(b[idx]) * a0) % MOD + MOD) % MOD;
        return (a0 * v[idx] + b0) % MOD;
    }

private:
    const int MOD = 1e9 + 7;
    vector<int> v, a, b;

    int inv(int x) { return quickmul(x, MOD-2); }

    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y&1) {
                ret = static_cast<long long>(ret) * cur % MOD;
            }
            cur = static_cast<long long>(cur) * cur % MOD;
            y>>=1;
        }
        return ret;
    }
};
