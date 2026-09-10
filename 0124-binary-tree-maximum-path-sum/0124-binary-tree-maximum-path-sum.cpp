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
    int a = -1e9;
    int rec(TreeNode* root){
        if(!root) return -1e9;

        int ans = root->val;

        int sum1 = rec(root->left);
        int sum2 = rec(root->right);
        ans = max(ans, sum1 + root->val);
        ans = max(ans, sum2 + root->val);
        a = max(a, sum1);
        a = max(a, sum2);
        a = max(a , sum1 + sum2 + root->val);
        a = max(a, ans);


        return ans;
    }

    int maxPathSum(TreeNode* root) {
        a = -1e9;
        rec(root);
        return a;
    }
};