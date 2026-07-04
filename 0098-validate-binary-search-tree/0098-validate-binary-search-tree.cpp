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
bool issorted(vector<int>ans){
    int n=ans.size();
    for(int i=0;i<=n-2;i++){
        if(ans[i]>=ans[i+1]) return false;
    }
    return true;
}
void inorder(TreeNode* root,vector<int>& ans){
    if(root==NULL) return ;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return issorted(ans);
    }
};