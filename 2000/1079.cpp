// 1079. Letter Tile Possibilities
class Solution {
public:
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        sort(tiles.begin(), tiles.end());
        return solve(tiles, "", 0) - 1;
    }

private:
    int n;
    unordered_set<string> patterns;

    int solve(string& tiles, string currPattern, int pos) {
        if (pos >= n) {
            if (patterns.insert(currPattern).second)
                return countPerm(currPattern);
            return 0;
        }

        return solve(tiles, currPattern, pos+1) +
            solve(tiles, currPattern+tiles[pos], pos+1);
    }

    int countPerm(string& pattern) {
        int count[26] = {0};
        for (char c: pattern)   count[c-'A']++;

        int result = factorial(pattern.size());
        for (int i: count) {
            if (i > 1) 
                result /= factorial(i);
        }
        return result;
    }

    int factorial(int n) {
        int result = 1;
        while (n>1) {
            result *= n;
            --n;
        }
        return result;
    }
};
