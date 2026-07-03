class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void nthlevel(TreeNode* root, int curr, int level, vector<int>& v) {
        if (root == NULL)
            return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        nthlevel(root->left, curr + 1, level, v);
        nthlevel(root->right, curr + 1, level, v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(level(root),0);
        int n=ans.size();
        for(int i=0;i<n;i++){
            vector<int> v;
            nthlevel(root, 0, i, v);
            ans[i]=v[v.size()-1];
        }
        return ans;
    }
};