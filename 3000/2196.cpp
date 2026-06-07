// 2196. Create Binary Tree From Descriptions

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for (auto& des: descriptions) {
            const int parent = des[0];
            const int child = des[1];
            if (nodeMap.count(parent)==0)
                nodeMap[parent] = new TreeNode(parent);
            if (nodeMap.count(child)==0)
                nodeMap[child] = new TreeNode(child);

            if (des[2]) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }

            children.insert(des[1]);
        }

        for (auto& x: nodeMap) {
            if (children.find(x.first) == children.end())
                return x.second;
        }

        return nullptr;
    }
};
