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
vector<vector<int>>ans;
int mx=0;
void check(TreeNode* root,int level)
{
    if(root==nullptr)return;
    mx=max(mx,level);
    check(root->right,level+1);
    check(root->left,level+1);
}
void bfs(TreeNode* root,int level)
{
    if(root==nullptr)return;
    ans[level].push_back(root->val);
    bfs(root->left,level+1);
    bfs(root->right,level+1);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        check(root,0);
        ans.resize(mx+1);
        bfs(root,0);
        return ans;
    }
};
