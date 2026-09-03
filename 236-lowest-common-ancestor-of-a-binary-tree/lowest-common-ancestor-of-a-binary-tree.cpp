class Solution {
public:
    TreeNode* ans = NULL;

    int helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return 0;

        int left = helper(root->left, p, q);
        int right = helper(root->right, p, q);

        int self = (root == p || root == q) ? 1 : 0;
        int total = left + right + self;

        if (total == 2 && ans == NULL) {
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        helper(root, p, q);
        return ans;
    }
};