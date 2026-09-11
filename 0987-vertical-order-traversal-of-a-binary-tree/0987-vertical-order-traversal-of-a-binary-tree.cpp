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

    void rec(TreeNode* root, int idx, int jdx,map<int,vector<pair<int,int>>> &ans){
        if(!root) return;
        
        ans[idx].push_back({jdx,root->val});

        rec(root->left,idx-1,jdx+1,ans);
        rec(root->right,idx+1,jdx+1,ans);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> map;

        vector<vector<int>> ans;
        rec(root,0,0,map);
        for(auto &[x,v] : map){
            vector<pair<int,int>> hold = v;
            sort(hold.begin(),hold.end());
            ans.push_back({});
            int n = ans.size() - 1;

            for(int i=0;i<hold.size();i++){
                ans[n].push_back(hold[i].second);
            }
        }

        return ans;
    }
};