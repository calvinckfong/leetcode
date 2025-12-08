// 1925. Count Square Sum Triples
class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> S;
        auto hash = [](int a, int b) { return (a-1)*250+(b-1); };
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (S.find(hash(i,j)) == S.end()) {
                    int sq_sum = i*i + j*j;
                    int rms = sqrt(sq_sum);
                    if (rms<=n && rms*rms == sq_sum) {
                        S.insert(hash(i,j));
                        S.insert(hash(j,i));
                    }
                }
            }
        }

        return S.size();
    }
};
