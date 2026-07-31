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
int g_max=0;
int dia(TreeNode* root)
{
    if(root==nullptr)return 0;
    int lheight=dia(root->left);
    int rheight=dia(root->right);
    g_max=max(g_max,lheight+rheight+1);
    return max(lheight,rheight)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return g_max-1;
    }
};
