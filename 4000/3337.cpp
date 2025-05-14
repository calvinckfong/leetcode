// 3337. Total Characters in String After Transformations II

const int MOD = 1e9 + 7;

class Mat {
public:
    static const int N = 26;
    int data[N][N];

    Mat() {
        memset(data, 0, sizeof(data));
    } 
    Mat I() {
        Mat w;
        for (int i=0; i<N; i++)
            w.data[i][i] = 1;
        return w;
    }
    Mat(const Mat& m) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                data[i][j] = m.data[i][j];
        }
    }
    Mat& operator=(const Mat& m) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                data[i][j] = m.data[i][j];
        }
        return *this;
    }
    Mat operator*(const Mat& v) {
        Mat w;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                for (int k=0; k<N; k++) {
                    w.data[i][j] = 
                        (w.data[i][j] + (long long)data[i][k] * v.data[k][j]) % MOD;
                }
            }
        }
        return w;
    }
    Mat multiply(int t) {
        Mat res = I(), cur = *this;
        while (t) {
            if (t&1) res = res * cur;
            cur = cur * cur;
            t /= 2;
        }
        return res;
    }
};

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = nums.size();
        Mat T;
        for (int i=0; i<26; i++) {
            for (int j=1; j<=nums[i]; j++) {
                T.data[(i+j)%26][i] = 1;
            }
        }

        Mat res = T.multiply(t);
        int result = 0;
        int cnt[26] = {0};
        for (char& c: s)    cnt[c-'a']++;

        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                result = 
                    (result + (long long)res.data[i][j]*cnt[j]) % MOD;
            }
        }
        return result;
    }
};
