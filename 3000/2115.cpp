// 2115. Find All Possible Recipes from Given Supplies
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> availSupplies;
        unordered_map<string, int> recipeToIdx;
        unordered_map<string, vector<string>> dep;

        for (string& sup: supplies) {
            availSupplies.insert(sup);
        }

        int nRec = recipes.size();
        for (int i=0; i<nRec; i++) {
            recipeToIdx[recipes[i]] = i;
        }

        vector<int> inDegree(nRec, 0);

        for (int i=0; i<nRec; i++) {
            for (string& ing : ingredients[i]) {
                if (!availSupplies.count(ing)) {
                    dep[ing].push_back(recipes[i]);
                    inDegree[i]++;
                }
            }
        }

        queue<int> q;
        for (int i=0; i<nRec; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<string> result;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            string rec = recipes[idx];
            result.push_back(rec);

            if (!dep.count(rec)) continue;

            for (string& d : dep[rec]) {
                if (--inDegree[recipeToIdx[d]] == 0) {
                    q.push(recipeToIdx[d]);
                }
            }
        }
        return result;
    }
};
