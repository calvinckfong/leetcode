// 3501. Maximize Active Section with Trade II
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        int ones = count(s.begin(), s.end(), '1');
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = (s[i - 1] == s[i]) ? left[i - 1] + 1 : 1;
        }

        right[n-1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = (s[i + 1] == s[i]) ? right[i + 1] + 1 : 1;
        }

        vector<int> ans(m, -1);
        int block_size = (int)sqrt(n);
        vector<tuple<int, int, int, int>> longQ;

        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (r - l + 1 > block_size) {
                longQ.push_back({l / block_size, l, r, i});
            } else {
                ans[i] = ones + brute_force(l, r, s);
            }
        }

        sort(longQ.begin(), longQ.end(),
             [](const tuple<int, int, int, int>& a,
                const tuple<int, int, int, int>& b) {
                 if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
                 return get<2>(a) < get<2>(b);
             });

        deque<int> subZeros;
        int L = 0, R = 0, bestGain = 0;

        for (int i = 0; i < longQ.size(); i++) {
            int bid = get<0>(longQ[i]);
            int l = get<1>(longQ[i]);
            int r = get<2>(longQ[i]);
            int qid = get<3>(longQ[i]);

            if (i == 0 || bid > get<0>(longQ[i - 1])) {
                L = (bid + 1) * block_size - 1; 
                R = (bid + 1) * block_size;
                subZeros.clear();
                bestGain = 0;
            }

            while (R <= r) {
                int sz = min(r - R + 1, right[R]);
                if (s[R] == '0') {
                    if (!subZeros.empty() && s[R - 1] == '0') {
                        subZeros.back() += sz;
                    } else {
                        subZeros.push_back(sz);
                    }
                    if (subZeros.size() >= 2) {
                        bestGain = max(subZeros.back() + subZeros[subZeros.size() - 2], bestGain);
                    }
                }
                R += sz;
            }

            int tmp_bestGain = bestGain;
            int tmp_firstValue = subZeros.empty() ? -1 : subZeros.front();
            int cnt = 0;

            while (L >= l) {
                int sz = min(L - l + 1, left[L]);
                if (s[L] == '0') {
                    if (!subZeros.empty() && s[L + 1] == '0') {
                        subZeros.front() += sz;
                    } else {
                        subZeros.push_front(sz);
                        cnt++;
                    }
                    if (subZeros.size() >= 2) {
                        bestGain = max(subZeros[0] + subZeros[1], bestGain);
                    }
                }
                L -= sz;
            }

            ans[qid] = bestGain + ones;
            L = (bid + 1) * block_size - 1;
            bestGain = tmp_bestGain;
            for (int j = 0; j < cnt; j++) {
                subZeros.pop_front();
            }
            if (tmp_firstValue != -1) {
                subZeros[0] = tmp_firstValue;
            }
        }
        return ans;
    }

private:
    int brute_force(int l, int r, string& s) {
        int i = l;
        int res = 0;
        int prev = INT_MIN;

        while (i <= r) {
            int start = i;
            while (i <= r && s[i] == s[start]) {
                i++;
            }
            if (s[start] == '0') {
                int cur = i - start;
                res = (prev != INT_MIN && prev + cur > res) ? prev + cur : res;
                prev = cur;
            }
        }
        return res;
    };
};
