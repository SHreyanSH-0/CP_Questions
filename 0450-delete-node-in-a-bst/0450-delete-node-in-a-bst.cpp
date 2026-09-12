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

    void insert(TreeNode* root, TreeNode* node){
        if(root->val < node->val) {
            if(root->right) insert(root->right,node);
            else root->right = node;
        }
        else{
            if(root->left) insert(root->left,node);
            else root->left = node;
        }
    }

    void d(TreeNode* node, TreeNode* par, int key){
        if(!node) return;
        if(node->val == key){
            if(node->right == nullptr) {
                if(node->val > par->val){
                    par->right = node->left;
                }
                else{
                    par->left = node->left;
                }
            }
            else{
                if(node->val > par->val){
                    par->right = node->right;
                }
                else{
                    par->left = node->right;
                }
                if(node->left){
                    insert(node->right, node->left);
                }
            }
        }
        else if(node->val > key){
            d(node->left,node,key);
        }
        else{
            d(node->right,node,key);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;

            insert(root->right, root->left);
            return root->right;
        }
        d(root,nullptr,key);
        return root;
    }
};