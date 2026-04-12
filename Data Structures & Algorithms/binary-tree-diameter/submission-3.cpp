class Solution {
    int dia = 0;

public:
    int d(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int left = d(root->left);
        int right = d(root->right);

        dia = max(dia, left + right);   // ✅ update diameter

        return 1 + max(left, right);    // height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        d(root);
        return dia;
    }
};