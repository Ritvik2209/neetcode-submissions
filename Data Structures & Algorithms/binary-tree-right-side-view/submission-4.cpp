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
  vector<int>ans;
  int mx=0;
  void find(TreeNode*root,int level)
  {
if(root==nullptr)return;
    mx=max(mx,level);
    find(root->left,level+1);
    find(root->right,level+1);
  }
void traversal(TreeNode* root,int level)
{
    if(root==nullptr)return;
    ans[level]=root->val;
    traversal(root->left,level+1);
    traversal(root->right,level+1);

}
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        find(root,0);
        ans.resize(mx+1);
        traversal(root,0);
        return ans;
       
    }
};
