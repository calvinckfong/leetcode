// 959. Regions Cut By Slashes
class Solution {
public:
    // solve using union set
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int numNodePerSide = n+1;
        int totalNodes = numNodePerSide * numNodePerSide;
        m_graph = vector<int>(totalNodes, -1);

        // connect nodes at borders
        for (int i=0; i<numNodePerSide; i++) {
            for (int j=0; j<numNodePerSide; j++) {
                if (i==0 || j==0 || i==n || j==n) {
                    m_graph[i*numNodePerSide+j] = 0;
                }
            }
        }

        // Initialize first node
        m_graph[0] = -1;
        int result = 1;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='/') {
                    int tr = i*numNodePerSide+j+1;
                    int bl = (i+1)*numNodePerSide+j;
                    result += union_set(tr, bl);
                } else if (grid[i][j]=='\\') {
                    int tl = i*numNodePerSide+j;
                    int br = (i+1)*numNodePerSide+j+1;
                    result += union_set(tl, br);
                }
            }
        }
        return result;
    }

private:
    vector<int> m_graph;

    int union_set(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return 1; // same set

        m_graph[p2] = p1;   
        return 0;
    }

    int find(int node) {
        if (m_graph[node] == -1) return node;
        return m_graph[node] = find(m_graph[node]);
    }
};
