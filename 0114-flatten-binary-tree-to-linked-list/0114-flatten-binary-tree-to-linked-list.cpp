class Solution {
public:
vector<TreeNode* > preorder(TreeNode* root){
    vector<TreeNode* > v;
    if(root== NULL) return v;
    v.push_back(root);
    vector<TreeNode* > left=preorder(root->left);
    vector<TreeNode* > right=preorder(root->right);
    v.insert(v.end(),left.begin(),left.end());
    v.insert(v.end(),right.begin(),right.end());
    return v;
}
    void flatten(TreeNode* root) {
        vector<TreeNode* > ans;
        if(root==NULL) return ;
        ans=preorder(root);
        int n=ans.size();
        for(int i=1;i<n;i++){
            ans[i-1]->right=ans[i];
            ans[i-1]->left=NULL;
        }
        ans[n-1]->right=NULL;
          ans[n-1]->left=NULL;
            return ;
    }
};