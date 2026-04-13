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
    bool h(TreeNode* root,int lb, int ub){
            if(!root){
                return true;
            }
            if((root->val>=ub||root->val<=lb)||(root->right && root->right->val<=root->val) || (root->left && root->left->val>=root->val)){
                return false; 
            }else{
                return h(root->left,lb,root->val)&&h(root->right,root->val,ub);           
            }   
    }
    bool isValidBST(TreeNode* root) {
        return h(root,INT_MIN,INT_MAX);
           
    }
};
