// 3607. Power Grid Maintenance
class Vertex {
    public:
        int vertexId;
        bool offline = false;
        int gridId = -1;

        Vertex() {}
        Vertex(int id) : vertexId(id) {}
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> graph(c+1);

        vertices.resize(c+1);
        for (int i=1; i<=c; i++) {
            vertices[i] = Vertex(i);
        }

        for (auto& c: connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<priority_queue<int, vector<int>, greater<int>>> powerGrids;
        for (int i=1, pgid=0; i<=c; i++) {
            auto& vtx = vertices[i];
            if (vtx.gridId == -1) {
                priority_queue<int, vector<int>, greater<int>> pq;
                traverse(vtx, pgid, pq, graph);
                powerGrids.push_back(pq);
                pgid++;
            }
        }

        vector<int> res;
        for (auto& q: queries) {
            int x = q[1];
            if (q[0] == 1) {
                if (!vertices[x].offline) {
                    res.push_back(x);
                } else {
                    auto& pg = powerGrids[vertices[x].gridId];
                    while (!pg.empty() && vertices[pg.top()].offline) {
                        pg.pop();
                    }
                    res.push_back(!pg.empty()?pg.top():-1);
                }
            } else if (q[0] == 2) {
                vertices[x].offline = true;
            }
        }

        return res;
    }

private:
    vector<Vertex> vertices;

    void traverse(Vertex& u, int pgid, priority_queue<int, vector<int>, greater<int>>& pq, 
            vector<vector<int>>& graph) {
        u.gridId = pgid;
        pq.push(u.vertexId);
        for (int vid: graph[u.vertexId]) {
            Vertex& v = vertices[vid];
            if (v.gridId == -1)
                traverse(v, pgid, pq, graph);
        }
    }
};
