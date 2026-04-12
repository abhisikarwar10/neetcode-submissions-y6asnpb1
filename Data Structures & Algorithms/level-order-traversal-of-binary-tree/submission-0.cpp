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
    vector<vector<int>> out;
    void h(TreeNode* root,int level){
        if(!root){
            return;
        }
        if(out.size()>level){
            out[level].push_back(root->val);
        }else{
            vector<int> a;
            a.push_back(root->val);
            out.push_back(a);
        }
        h(root->left,level+1);
        h(root->right,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        h(root,0);
        return out;
    }
};
