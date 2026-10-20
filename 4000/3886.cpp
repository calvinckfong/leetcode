// 3886. Sum of Sortable Integers
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> factor;
        for (int i=1; i*i<=n; i++) {
            if (n%i == 0) {
                factor.push_back(i);
                if (n/i != i) {
                    factor.push_back(n/i);
                }
            }
        }

        vector<int> tar = nums;
        sort(tar.begin(), tar.end());

        int res = 0;
        for (int x: factor) {
            bool ok = true;
            for (int l=0; l<n; l+=x) {
                int r = l+x-1;
                vector<int> sub1(nums.begin()+l, nums.begin()+r+1);
                vector<int> sub2(tar.begin()+l, tar.begin()+r+1);
                if (!check(sub1, sub2)) {
                    ok = false;
                    break;
                }
            }
            if (ok) res += x;
        }
        return res;
    }

private:
    bool check(const vector<int>& a, const vector<int>& b) {
        int n = a.size();
        for (int i=0; i<n-1; i++) {
            if (a[i] > a[i+1]) {
                vector<int> rotated;
                rotated.insert(rotated.end(), a.begin()+i+1, a.end());
                rotated.insert(rotated.end(), a.begin(), a.begin()+i+1);
                return rotated == b;
            }
        }
        return a == b;
    }
};
