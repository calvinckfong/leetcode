// 399. Evaluate Division
class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    void BuildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i=0; i<equations.size(); i++)
        {
            auto eq = equations[i];
            graph[eq[0]][eq[1]] = values[i];
            graph[eq[1]][eq[0]] = 1.0/values[i];
        }
    }

    double Query(vector<string> query)
    {
        if (graph.find(query[0])==graph.end() || graph.find(query[1])==graph.end())
            return -1.0;

        double result = -1.0;
        unordered_set<string> visited;
        GraphSearch(query[0], query[1], visited, 1.0, result);

        return result;
    }

    void GraphSearch(string dividend, string divisor, unordered_set<string>& visited, double prev, double& result)
    {
        // already visited
        if (visited.find(dividend)!=visited.end()) return;

        visited.insert(dividend);
        if (dividend == divisor) // reach
        {  
            result = prev;
            return;
        }

        for (auto node: graph[dividend])
            GraphSearch(node.first, divisor, visited, prev*node.second, result);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        BuildGraph(equations, values);
        int nQuery = queries.size();
        vector<double> result(nQuery);
        for (int i=0; i<nQuery; i++)
            result[i] = Query(queries[i]);
        return result;
    }
};
