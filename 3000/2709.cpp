// 2709. Greatest Common Divisor Traversal
class UnionFind {    
private:
    int count;
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) :
        count(n), parent(n), rank(n, 0)
    {
        for (int i=0; i<n; i++)
            parent[i] = i;
    }

    ~UnionFind() {}
    
    void push(int x) {

    }
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void merge(int x, int y) {
        int xset = find(x);
        int yset = find(y);

        if (xset == yset) return;
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
        else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        // early stop conditions
        if (n==1) return true;
        if (find(nums.begin(), nums.end(), 1) != nums.end()) return false;

        // Build prime factors of each numbers <= maxVal
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> sieve(maxVal+1, 0);
        for (int i=2; i<=maxVal; i++)
        {
            if (sieve[i]==0) {
                for (int j=i; j<=maxVal; j+=i) {
                    sieve[j] = i;
                    // printf("sieve[%d] = %d\n", j, i);
                }
            }
        }

        // Group by union find
        UnionFind uf(maxVal+1);
        for (int x: nums) {
            int val = x;
            while (val>1) {
                // merge with all its prime factors
                int prime = sieve[val];
                if (uf.find(x) != uf.find(prime))
                {
                    uf.merge(x, prime);
                }
                val /= prime;
            }
            
        }

        // check number of unconnected groups in Union Find
        int cnt = 0;
        set<int> numSet(nums.begin(), nums.end());
        for (int i: numSet)
        {
            if (uf.find(i) == i) cnt++;
        }
        return cnt==1;
    }
};

