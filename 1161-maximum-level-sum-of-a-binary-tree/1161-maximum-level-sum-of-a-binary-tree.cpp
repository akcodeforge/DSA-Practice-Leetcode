class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int l = 1;
        int ans = 1;
        int maxi = INT_MIN;

        while (!q.empty()) {
            int n = q.size();
            int sum = 0;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            if (sum > maxi) {
                maxi = sum;
                ans = l;
            }

            l++;
        }

        return ans;
    }
};