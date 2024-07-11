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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<TreeNode*> Q;
        Q.push(NULL);
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* cur = Q.front();
            Q.pop();

            if (cur == NULL) {
                if (!Q.empty()) {
                    res.push_back(Q.front()->val);
                    Q.push(NULL);
                }
            }
            else {
                if (cur->right != NULL) {
                    Q.push(cur->right);
                }
                if (cur->left != NULL) {
                    Q.push(cur->left);
                }
            }

        }
        return res;
    }
};