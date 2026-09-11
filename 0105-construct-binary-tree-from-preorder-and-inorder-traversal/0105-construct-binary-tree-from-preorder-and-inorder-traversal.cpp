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

    TreeNode* rec(vector<int> &preorder, vector<int> &inorder,unordered_map<int,int> &ind, int inStart, int inEnd, int preStart, int preEnd){
        if(inStart > inEnd || preStart > preEnd) return nullptr;
        TreeNode* hold = new TreeNode(preorder[preStart]);
        int rootIndex = ind[preorder[preStart]];
        int x = rootIndex - inStart;
        hold->left = rec(preorder, inorder, ind, inStart, rootIndex - 1, preStart + 1, preStart + x);
        hold->right = rec(preorder, inorder, ind, rootIndex + 1, inEnd, preStart + x + 1, preEnd);

        return hold;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> ind;
        int n = inorder.size();
        for(int i=0;i<inorder.size();i++){
            ind[inorder[i]] = i;
        }
        TreeNode* node = rec(preorder,inorder,ind,0,n-1,0,n-1);
        return node;
    }
};