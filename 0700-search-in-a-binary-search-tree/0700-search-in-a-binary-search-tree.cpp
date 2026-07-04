class Solution {
public:
    TreeNode* search(TreeNode* root, int val) {
        if (root== NULL)
            return NULL;
        if (root->val == val)
            return root;
        else if (val < root->val) {
            return search(root->left, val);
        } else {
            return search(root->right, val);
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val)
            return root;
        else if (val < root->val) {
            return search(root->left, val);
        } else {
            return search(root->right, val);
        }
        return NULL;
    }
};