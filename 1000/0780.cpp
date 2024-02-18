// 780. Reaching Points
class Solution {
public:
    queue<pair<int, int>> q;
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx==tx && sy==ty) return true;
        if (sx>tx || sy>ty) return false;

        // Reduce tx and ty:
        while (tx>sx && ty>sy)
        {
            if (tx>ty)  tx = tx%ty;
            else        ty = ty%tx;
        }

        // when tx=sx, we only need to check if ty = sy + n*sx, or vise versa
        if (tx==sx && (ty-sy)%sx==0) return true;
        if (ty==sy && (tx-sx)%sy==0) return true;

        return false;
    }
};
