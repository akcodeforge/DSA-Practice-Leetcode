class Solution {
public:
    int solve(TreeNode* root, int maxV) {
        if (root == nullptr)
            return 0;

        int count = 0;

        if (root->val >= maxV) {
            count = 1;
            maxV = root->val;
        }

        count += solve(root->left, maxV);
        count += solve(root->right, maxV);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};