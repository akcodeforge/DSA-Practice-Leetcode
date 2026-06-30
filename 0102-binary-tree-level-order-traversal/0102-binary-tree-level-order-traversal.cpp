class Solution {
public:
    int level(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }
    void lOrder(TreeNode* root,vector<vector<int>>& ans,int level) {
        if(root==NULL) return;
        ans[level].push_back(root->val);
        lOrder(root->left,ans,level+1);
        lOrder(root->right,ans,level+1); 
    }
    vector<vector<int>> levelOrder(TreeNode* root) { 
        vector<vector<int>> ans; 
        int n = level(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            ans.push_back(v);  
        }
        lOrder(root,ans,0); 
        return ans;
        }
};