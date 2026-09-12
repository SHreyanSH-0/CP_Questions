/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node) s.append(to_string(node->val) + ",");
            else s.append("#,");
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.

    vector<int> decode(string data){
        vector<int> ans;
        // cout<<data<<endl;
        for(int i=0;i<data.size();i++){
            if(data[i] == '#'){
                ans.push_back(1001);
                i++;
                continue;
            }
            int val = 0;
            int sign = 1;
            if(data[i] == '-') sign = -1, i++;
            while(i<data.size() && data[i] != ','){
                val = val*10 + (data[i] - '0');
                // cout<<i<<" "<<data[i]<<" "<<val<<endl;
                i++;
            }
            // cout<<data[i]<<" ";
            ans.push_back(sign * val);
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;

        vector<int> val = decode(data);
        int n = val.size();

        TreeNode* root = new TreeNode(val[0]);
        int idx = 1;

        queue<TreeNode*> q; 

        for(int i=0;i<n;i++) cout<<val[i]<<" ";

        q.push(root);
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            if(idx < n && val[idx] != 1001){
                it->left = new TreeNode(val[idx]);
                q.push(it->left);
            }

            idx++;

            if(idx < n && val[idx] != 1001){
                it->right = new TreeNode(val[idx]);
                q.push(it->right);
            }

            idx++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));