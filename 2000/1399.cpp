// 1399. Count Largest Group
class Solution {
public:
    int countLargestGroup(int n) {
        int map[100] = {0};
        int maxVal = 0;
        
        for (int i=1; i<=n; i++) {
            int key=0, j=i;
            while (j) {
                key += j%10;
                j /= 10;
            }
            map[key]++;
            if (map[key] > maxVal) {
                maxVal = map[key];
            }
        }

        int result = 0;
        for (int i=0; i<100; i++) {
            if (map[i] == maxVal) {
                result++;
            }
        }
        return result;
    }
};
