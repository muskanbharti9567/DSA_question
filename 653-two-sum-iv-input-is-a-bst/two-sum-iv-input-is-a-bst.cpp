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

    void getSmall(TreeNode* root, stack<TreeNode*>& s) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }

    void getBig(TreeNode* root, stack<TreeNode*>& s) {
        while(root) {
            s.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> small, big;

        getSmall(root, small);
        getBig(root, big);

        while(!small.empty() && !big.empty()) {

            int a = small.top()->val;
            int b = big.top()->val;

            if(a >= b)
                return false;

            if(a + b == k)
                return true;

            if(a + b < k) {
                TreeNode* node = small.top();
                small.pop();

                getSmall(node->right, small);
            }
            else {
                TreeNode* node = big.top();
                big.pop();

                getBig(node->left, big);
            }
        }

        return false;
    }
};