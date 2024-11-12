// 2070. Most Beautiful Item for Each Query
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int qSize = queries.size();
        int iSize = items.size();

        vector<int> result(qSize);

        sort(items.begin(), items.end());

        vector<vector<int>> qWithIdx(qSize, vector<int>(2));
        for (int i=0; i<qSize; i++) {
            qWithIdx[i][0] = queries[i];
            qWithIdx[i][1] = i;
        }

        sort(qWithIdx.begin(), qWithIdx.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int idx=0, maxBeauty=0;
        for (int i=0; i<qSize; i++) {
            int q = qWithIdx[i][0];
            int oldIdx = qWithIdx[i][1];

            while (idx<iSize && items[idx][0] <= q) {
                maxBeauty = max(maxBeauty, items[idx][1]);
                idx++;
            }
            result[oldIdx] = maxBeauty;
        }
        return result; 
    }
};
