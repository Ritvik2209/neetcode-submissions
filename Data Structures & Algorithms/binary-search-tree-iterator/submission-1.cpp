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
class BSTIterator {
public:
vector<int>in_order;
int i=-1;
void in_order_traversal(TreeNode* node)
{
    if(node->left!=nullptr)in_order_traversal(node->left);
    in_order.push_back(node->val);
    if(node->right!=nullptr)in_order_traversal(node->right);
}
    BSTIterator(TreeNode* root) {
        in_order_traversal(root);
    }
    
    int next() {
        i++;
        return in_order[i];
    }
    
    bool hasNext() {
        if(i==-1)return true;
        if(i<in_order.size()-1)return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */