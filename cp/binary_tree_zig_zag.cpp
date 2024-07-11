/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        stack<TreeNode*> St;
        St.push(root);
        int level = 1;
        while (!St.empty()) {
            // for every level
            vector<int> ans;
            stack<TreeNode*> tempSt;
            while (!St.empty()) {
                TreeNode* cur = St.top();
                St.pop();
                if (cur == NULL) continue;
                ans.push_back(cur->val);

                if (level % 2) {
                    // push left then right
                    tempSt.push(cur->left);
                    tempSt.push(cur->right);
                }
                else {
                    // push right then left
                    tempSt.push(cur->right);
                    tempSt.push(cur->left);
                }
            }
            swap(St, tempSt);
            level++;
            if (!ans.empty())
                res.push_back(ans);
        }
        return res;
    }
};