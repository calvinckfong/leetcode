// 2192. All Ancestors of a Node in a Directed Acyclic Graph
class Node {
public:
    int m_val;
    vector<Node*> m_parents;

    Node(int v) : m_parents() { m_val = v; }
};

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<Node*> T(n);
        for (int i=0; i<n; i++) T[i] = new Node(i);

        for (int i=0; i<edges.size(); i++) {
            T[edges[i][1]]->m_parents.push_back(T[edges[i][0]]);
        }
        
        vector<vector<int>> result(n);
        for (int i=0; i<n; i++) {
            set<int> parents;
            getParents(T[i], parents);
            result[i] = vector(parents.begin(), parents.end());
        }
        return result;
    }

private:
    void getParents(Node* node, set<int>& parents) {
        for (int i=0; i<node->m_parents.size(); i++) {
            if (parents.find(node->m_parents[i]->m_val) == parents.end()) {
                parents.insert(node->m_parents[i]->m_val);
                getParents(node->m_parents[i], parents);
            }
        }
    }
};
