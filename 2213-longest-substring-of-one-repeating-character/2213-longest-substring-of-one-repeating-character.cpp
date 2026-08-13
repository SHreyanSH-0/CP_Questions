class Solution {
public:

    struct node{
        int maxi = -1;
        int left = -1;
        int right = -1;
        char lc;
        char rc;
    };

    node merge(node&l, node&r, int llen, int rlen){
        node hold;

        hold.maxi = max(l.maxi, r.maxi);

        if(l.rc == r.lc){
            if(l.maxi == llen){
                hold.left = l.left + r.left;
                hold.lc = l.lc;

                hold.maxi = max(hold.maxi, hold.left);    
            }

            if(r.maxi == rlen){
                hold.right = r.maxi + l.right;
                hold.rc = r.rc;

                hold.maxi = max(hold.maxi, hold.right);
            }

            if(l.right + r.left > hold.maxi){
                hold.maxi = l.right + r.left;
            }

            if(hold.right == -1){
                hold.right = r.right;
                hold.rc = r.rc;
            }
            if(hold.left == -1){
                hold.left = l.left;
                hold.lc = l.lc;
            }
        }
        else{
            hold.right = r.right;
            hold.rc = r.rc;
            hold.left = l.left;
            hold.lc = l.lc;
        }

        return hold;
    }

    void build(int i, int l, int r, string &s, vector<node>&seg){
        if(l == r){
            node hold;
            hold.maxi = 1;
            hold.lc = s[l];
            hold.rc = s[r];
            hold.left = 1;
            hold.right = 1;
            seg[i] = hold;
        }
        else{
            int mid = (l+r)/2;

            build(2*i + 1, l, mid, s, seg);
            build(2*i + 2, mid + 1, r, s, seg);

            seg[i] = merge(seg[2*i + 1] , seg[2*i+2], mid - l + 1, r - mid);
        }
    }

    void update(int i, int l, int r, int idx, char c,vector<node>&seg){
        if(l == r){
            node hold;
            hold.maxi = 1;
            hold.lc = c;
            hold.rc = c;
            hold.left = 1;
            hold.right = 1;
            seg[i] = hold;
        }
        else{
            int mid = (l+r)/2;

            if(mid < idx){
                update(2*i+2, mid+1, r, idx, c, seg);
            }
            else{
                update(2*i+1, l, mid, idx, c, seg);
            }
            seg[i] = merge(seg[2*i+1], seg[2*i+2], mid - l + 1, r - mid);
            // cout<<seg[i].maxi<<" "<<seg[i].left<<" "<<seg[i].lc<<" \n";
        }
    }

    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        vector<int> ans(qi.size());
        int n = s.size();
        vector<node> seg(4*n);
        build(0,0,n-1,s,seg);
        for(int i=0;i<qc.size();i++){
            update(0,0,n-1,qi[i],qc[i],seg);
            ans[i] = seg[0].maxi;
        }

        return ans;
    }
};