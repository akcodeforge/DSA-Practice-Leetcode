class Solution {
public:
TreeNode* build(vector<int>& post,int postlo,int posthi, vector<int>& in,int inlo,int inhi){
    if(postlo>posthi) return NULL;
    TreeNode* root= new TreeNode(post[posthi]);
    if(postlo==posthi) return root;
    int i=inlo;
    while(i<=inhi){
        if(in[i]==post[posthi]) break;
        i++;
    }
    int leftcount=i-inlo;
    int rightcount=inhi-i;
    root->left=build(post,postlo,postlo+leftcount-1,in,inlo,i-1);
    root->right=build(post,postlo+leftcount,posthi-1,in,i+1,inhi);
    return root;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=post.size();
        return build(post,0,n-1,in,0,n-1);
    }
};