class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val>val){   ///go left
            if(root->left==NULL){
                TreeNode* temp=new TreeNode(val);
                root->left=temp;
                return root;
            }
            else insertIntoBST(root->left,val);
        }
        else{   /// go right
            if(root->right==NULL){
                TreeNode* temp=new TreeNode(val);
                root->right=temp;
                return root;
            }
            else insertIntoBST(root->right,val);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size();
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=1;i<n;i++){
        TreeNode* temp=new TreeNode(pre[i]);
            insertIntoBST(root,temp->val);
        }
        return root;
    }
};