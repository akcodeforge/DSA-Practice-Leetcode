class Solution {
public:
void helper(TreeNode* root,long long sum,int& count){
    if(root==NULL) return;
        if((long long)(root->val)==sum) {
            count++;
    }
    long long n=root->val;
    helper(root->left,sum-n,count);
    helper(root->right,sum-n,count);
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count=0;
        helper(root,(long long)(targetSum),count);
        count +=pathSum(root->left,(long long) (targetSum))+pathSum(root->right,(long long )(targetSum));
        return count;
    }
};