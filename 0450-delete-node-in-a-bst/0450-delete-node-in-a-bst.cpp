class Solution {
public:
    TreeNode* succesor(TreeNode* root) {
        TreeNode* suc = root->right;
        while (suc->left != NULL) {
            suc = suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key) {
            /// case 1: if have zero chile
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            } 
            if (root->left == NULL || root->right == NULL) {
                if (root->left != NULL) {
                    return root->left;
                }
                else{
                    return root->right;
                }
            } 
            if (root->left != NULL && root->right != NULL) {
                /// replae the root with its succ/pred
                ///  again a
                TreeNode* suc = succesor(root);
                root->val = suc->val;
                root->right = deleteNode(root->right, suc->val);
                return root;
            }
        } 
        else if (root->val > key) { /// go left for research
            root->left = deleteNode(root->left, key);
        } 
        else { /// go right beacuse root->val<key
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};