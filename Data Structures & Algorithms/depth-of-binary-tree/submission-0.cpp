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
    int ans = INT_MIN;
    int maxDepthlevel(TreeNode* root,int level) {
        if(root==nullptr){
            return level-1;
        }
        if(level>ans){
            ans = level;
        }
        maxDepthlevel(root->left,level+1);
        maxDepthlevel(root->right,level+1);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        return maxDepthlevel(root,1);
    }
};
