// 502. IPO
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> projects;
        for (int i=0; i<n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());

        int i=0;
        priority_queue<int> pq; 
        while (k--) {
            // add qualified project to pq starting from last unqalified project
            for (; i<n && w>=projects[i].first; i++) {
                pq.push(projects[i].second);
            }
            // if no project qualified, quit
            if (pq.empty()) break;
            // choose the project with highest profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
