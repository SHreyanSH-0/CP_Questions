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

    TreeNode* rec(vector<int>& preorder, int i , int ub, int lb){
        if(i >= preorder.size()) return nullptr;

        if(preorder[i] < lb || preorder[i] > ub) return rec(preorder,i+1,ub,lb);
        
        TreeNode* node = new TreeNode(preorder[i]);

        node->left = rec(preorder,i+1,node->val,lb);
        node->right = rec(preorder,i+1,ub, node->val);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return rec(preorder,0,INT_MAX,INT_MIN);
    }
};