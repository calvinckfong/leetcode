// 3518. Smallest Palindromic Rearrangement II
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int freq[26] = {0};

        for (int i=0; i<n/2; i++) {
            freq[s[i]-'a']++;
        }

        string l = "";
        long long startIdx = 1;
        for (int i=0; i<n/2; i++) {
            for (int j=0; j<26; j++) {
                if (freq[j]==0) continue;

                freq[j]--;

                long long ways = permutate(n/2 - i - 1, freq, k);
                if (startIdx + ways > k) {
                    l += ('a' + j);
                    break;
                }

                freq[j]++;
                startIdx += ways;
            }
        }

        if (l.size() < n/2) return "";

        string mid = (n%2) ? string(1, s[n/2]) : "";
        string r = l;
        reverse(r.begin(), r.end());

        return l + mid + r;
    }

private:
    long long permutate(int rem, int freq[], int k) {
        long long res = 1;
        for (int i=0; i<26; i++) {
            if (freq[i]==0) continue;

            res *= comb(rem, freq[i], k);
            if (res > k) break;
            rem -= freq[i];
        }
        return res;
    }

    long long comb(long long n, long long m, long long k) {
        long long res = 1;
        m = min(m, n-m);

        for (long long i=1; i<=m; i++) {
            res = res * (n-i+1) / i;
            if (res > k) return k+1;
        }
        return res;
    }
};
