/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 2326. Spiral Matrix IV
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int dirs[5] = {0, 1, 0, -1, 0};
        int d=0, u=0, v=0, dd, uu, vv;

        if (m==1) {
            while (head) {
                result[0][v++] = head->val;
                head = head->next;
            }
        } else if (n==1) {
            while (head) {
                result[u++][0] = head->val;
                head = head->next;
            }
        } 
        else
        {
            while (head) {
                result[u][v] = head->val;
                dd = 0;
                do { 
                    uu = u + dirs[d];
                    vv = v + dirs[d+1];
                    if (uu>=0 && vv>=0 && uu<m && vv<n && result[uu][vv]<0)
                        break;
                    d = (d+1)%4;
                    dd++;
                } while (dd <= 4);
                u = uu;
                v = vv;
                head = head->next;
            }
        }
        return result;
    }
};
