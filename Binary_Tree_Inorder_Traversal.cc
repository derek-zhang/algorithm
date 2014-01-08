/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode *root, vector<int> &res) {
        if (root == NULL) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    /*
    注意理解递归，最后一行实际上就是node = node->right,然后调进去后就是一直找left
    */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        deque<TreeNode*> node_queue;
        if (root == NULL) return res;
        TreeNode *node = root;
        while (!node_queue.empty() || node != NULL) {
            while(node) {
                node_queue.push_back(node);
                node = node->left;
            }
            node = node_queue.back();
            node_queue.pop_back();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};
