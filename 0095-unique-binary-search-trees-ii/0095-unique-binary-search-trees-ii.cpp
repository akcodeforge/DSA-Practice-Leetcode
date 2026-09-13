class Solution {
public:
    vector<TreeNode*> solve(int start,int end){
        if(start>end) return {nullptr};
        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftT=solve(start,i-1);
            vector<TreeNode*> rightT=solve(i+1,end);
            for(auto left:leftT){
                for(auto right:rightT){
                    TreeNode* z=new TreeNode(i);
                    z->left=left;
                    z->right=right;
                    ans.push_back(z);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};