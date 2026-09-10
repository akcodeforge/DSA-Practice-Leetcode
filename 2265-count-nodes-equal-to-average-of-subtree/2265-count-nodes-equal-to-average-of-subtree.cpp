#define pp pair<int,int>
class Solution {
public:
    pp f(TreeNode* root,int &ans){
        if(root==NULL) return {0,0};
        auto left=f(root->left,ans);
        auto right=f(root->right,ans);
        int sum=root->val+left.first+right.first;
        int count=1+left.second+right.second;
        if(sum/count==root->val) ans++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};