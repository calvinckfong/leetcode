// 2337. Move Pieces to Obtain a String
class Solution {
public:
    bool canChange(string start, string target) {
        if (start==target) return true;

        int n = start.size();
        int sIdx=0, tIdx=0;

        while (sIdx<n || tIdx<n) {
            while (sIdx<n && start[sIdx]=='_')  sIdx++;
            while (tIdx<n && target[tIdx]=='_') tIdx++;

            if (start[sIdx]!=target[tIdx]) return false;
            if (start[sIdx]=='L' && sIdx<tIdx) return false;
            if (start[sIdx]=='R' && sIdx>tIdx) return false;
            
            sIdx++;
            tIdx++;
        }
        return true;
    }
};
