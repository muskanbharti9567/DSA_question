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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);

        bool lefttoright = true;

        while(!q.empty()){
            int level_size = q.size();
            vector<int>temp(level_size);
            int first = 0;
            int last = level_size-1;

            while(level_size--){
                TreeNode*t = q.front();
                q.pop();

                if(lefttoright==true){
                    temp[first++]=t->val;
                }
                else{
                    temp[last--]=t->val;
                }

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

            }
            ans.push_back(temp);
            lefttoright = !lefttoright;
        }
        return ans;

        
    }
};