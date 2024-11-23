// 1861. Rotating the Box
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.'));

        for (int i=0; i<m; i++) {
            const int dst_col = m-i-1;
            int s_cnt=0, e_cnt=0;
            for (int j=0; j<n; j++) {
                if (box[i][j] == '#')
                    s_cnt++;
                else if (box[i][j] == '.')
                    e_cnt++;
                else {
                    result[j][dst_col] = '*';
                    while (s_cnt>0) {
                        result[j-s_cnt][dst_col] = '#';
                        s_cnt--;
                    }
                }
            }

            while (s_cnt>0) {
                result[n-s_cnt][dst_col] = '#';
                s_cnt--;
            }
        }

        return result;
    }
};
