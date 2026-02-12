#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    if(n==1) cout<<"-1"<<endl;
    else if(n==2){
        int diff = v[1] - v[0];

        if(diff==0) {
            cout<<1<<endl;
            cout<<v[0];
        }
        else if(diff%2==0){
            vector<int> ans = {v[0]-diff, v[1]+diff, v[0] + diff/2};
            sort(ans.begin(),ans.end());
            cout<<3<<endl;
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
            
        }
        else{
            cout<<2<<endl;
            cout<<v[0]-diff<<" "<<v[1]+diff;
        }
        
    }
    else{
        
        set<int> diff;
        
        for (int i = 0; i < n-1; i++)
        {
            diff.insert(v[i+1]-v[i]);
        }
        if(diff.size()==1&&*diff.begin()==0){
            cout<<1<<endl;
            cout<<v[0];
        }
        else if(diff.size()==1){
            cout<<2<<endl;
            cout<<v[0]-*diff.begin()<<" "<<v[n-1]+ *diff.begin();
        }
        else if(diff.size()==2){
            int diff1 = *diff.begin();
            int diff2;
            for(auto it:diff){
                diff2 = it;
            }

            int c1 = 0, c2 = 0;
            for (int i = 0; i < n-1; i++)
            {
                if(v[i+1]-v[i]==diff1){
                    c1++;
                }
                else{
                    c2++;
                }
            }

            if(c1>1&&c2>1){
                cout<<0<<endl;
            }
            else if(c1==1&&c2==1){
                if(max(diff1,diff2)==2*min(diff1,diff2)){
                    cout<<1<<endl;
                    for (int i = 0; i < n-1; i++)
                    {
                        if(v[i+1]-v[i]==max(diff1,diff2)){
                            cout<<v[i]+min(diff1,diff2);
                            return;
                        }
                    }
                }
                else cout<<0;
            }
            else{
                if(c1==1){
                    if(diff1 == 2*diff2){
                        cout<<1<<endl;
                        for (int i = 0; i < n-1; i++)
                        {
                            if(v[i+1]-v[i]==diff1){
                                cout<<v[i]+diff2;
                                return;
                            }
                        }
                    }
                    else{

                        cout<<0<<endl;
                    }
                }
                else{
                    int hold = diff1;
                    diff1 = diff2;
                    diff2 = hold;

                    if(diff1 == 2*diff2){
                        cout<<1<<endl;
                        for (int i = 0; i < n-1; i++)
                        {
                            if(v[i+1]-v[i]==diff1){
                                cout<<v[i]+diff2;
                                return;
                            }
                        }
                    }
                    else{
                        cout<<0<<endl;
                    }
                }
            }
        }
        else{
            cout<<0<<endl;
        }
        
    }
    
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
