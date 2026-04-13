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
    vector<int> out;
    void hl(TreeNode* root,int v,int h){
        if(!root){
            return;
        }
        if(out.size()>v){
            out[v] = root->val;            
        }else{
            out.push_back(root->val);
        }    
        hl(root->left,v+1,h-1);
        hl(root->right,v+1,h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        hl(root,0,0);
        return out;        
    }
};
