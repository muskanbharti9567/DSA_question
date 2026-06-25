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
    TreeNode* constructree(int start, int end, vector<int>& nums) {
        int mid = start + (end - start) / 2;
        if (start > end)
            return NULL;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = constructree(start, mid - 1, nums);
        node->right = constructree(mid + 1, end, nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructree(0, nums.size() - 1, nums);
    }
};