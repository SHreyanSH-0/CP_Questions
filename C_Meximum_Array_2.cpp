#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,k,q;
        cin>>n>>k>>q;
        vector<vector<int>> one;
        vector<vector<int>> two;
        
        for(int i=0;i<q;i++){
            int c,l,r;
            cin>>c>>l>>r;

            if(c==1){
                one.push_back({l,r});
            }
            else{
                two.push_back({l,r});
            }
        }
        vector<int> ans(n+1,-1);
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        int high = k+1;
        for (int i = 0; i < one.size(); i++)
        {
            for(int j=0;j<two.size();j++){
                int l1 = one[i][0];
                int r1 = one[i][1];
                int l2 = two[j][0];
                int r2 = two[j][1];
                int interl =0, interr=-1;
                if(l2>=l1&&l2<=r1){
                    interl = l2;
                    interr = min(r2,r1);
                }
                else if(l1>=l2&&l1<=r2){
                    interl = l1;
                    interr = min(r2,r1);
                }

                for(int j = interl;j<=interr;j++){
                    ans[j] = high;
                }
            }
        }

        for (int i = 0; i < one.size(); i++)
        {
            for(int j = one[i][0];j<=one[i][1];j++){
                if(ans[j]!=high){
                    ans[j] = k;
                }
            }
        }
        
        for (int i = 0; i < two.size(); i++)
        {
            set<int> s;
            for(int j=0;j<k;j++){
                s.insert(j);
            }
            for(int j = two[i][0];j<=two[i][1];j++){
                if(ans[j]!=high){
                    if(s.find(ans[j])!=s.end()){
                        s.erase(ans[j]);
                        continue;
                    }
                    if(s.empty()){
                        continue;
                    }
                    else{
                        ans[j] = *s.begin();
                        s.erase(*s.begin());
                    }
                }
            }
        }

        for (int i = 1; i <=n; i++)
        {
            if(ans[i]==-1) ans[i] = high;
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}