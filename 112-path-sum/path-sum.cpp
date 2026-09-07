class Solution {
public:
    bool result = false;

    void fun(TreeNode* root, int sum, int target) {
  
        if (root == NULL) {
            return;
        }

        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                result = true;
            }
            return;
        }

        fun(root->left, sum, target);
        fun(root->right, sum, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        fun(root, 0, targetSum);
        return result;
    }
};