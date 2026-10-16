// 2916. Subarrays Distinct Element Sum of Squares II
class BIT {
public:
    BIT(int n) {
        _size = n;
        _tree1.assign(n+2, 0);
        _tree2.assign(n+2, 0);
    }

    void add(int l, int r, int d) {
        _add(l, d);
        _add(r+1, -d);
    }

    long long query(int l, int r) {
        return _query(r) - _query(l-1);
    }

private:
    int _size;
    vector<long long> _tree1, _tree2;
    
    int _lowbit(int i) {
        return i & -i;
    }

    void _add(int i, int d) {
        long long rawIdx = ++i;
        while (i < _size) {
            _tree1[i] += d;
            _tree2[i] += rawIdx*d;
            i += _lowbit(i);
        }
    } 

    long long _query(int i) {
        long long rawIdx = (++i) + 1;
        if (i>_size) i = _size;
        
        long long res = 0;
        while (i>0) {
            res += rawIdx * _tree1[i] - _tree2[i];
            i -= _lowbit(i);
        }
        return res;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        long long res = 0, cur = 0;
        unordered_map<int, int> seen;
        BIT bit(n+10);

        for (int i=0; i<n; i++) {
            int x = nums[i];
            int j = (seen.count(x)?seen[x]:-1)+1;
            long long q = bit.query(j, i);
            cur = (cur + q*2 + i - j + 1) % MOD;
            res = (res + cur) % MOD;
            bit.add(j, i, 1);
            seen[x] = i;
        }

        return res;
    }
};
