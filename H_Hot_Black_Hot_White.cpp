#include <bits/stdc++.h>
using namespace std;
#define int long long
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

    vector<int> bit(n);
    int z = 0, o = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        int hold = v[i];
        int sum = 0;
        while(hold>0){
            sum += hold%10;
            hold/=10;
        }
        bit[i] = (sum*sum)%3;
        if(bit[i]==0) z++;
        else if(bit[i]==1) o++;
        else t++;
    }

    if(t==0){
        if(z>=n/2){
            cout<<2<<endl;
            string ans(n,'0');
            int ct = 0;
            for (int i = 0; i < n; i++)
            {
                if(bit[i]==0&&ct<n/2){
                    ans[i] = '1';
                    ct++;
                } 
            }
            cout<<ans;
        }
        else{
            cout<<0<<endl;
            string ans(n,'0');
            int ct = 0;
            for (int i = 0; i < n; i++)
            {
                if(bit[i]==1&&ct<n/2){
                    ans[i] = '1';
                    ct++;
                } 
            }
            cout<<ans;
        }
        
        return ;
    }


    if(z==n/2){
        cout<<0<<endl;
        for (int i = 0; i < n; i++)
        {
            if(bit[i]==0) cout<<1;
            else cout<<0;
        }
    }
    else if(z + o==n/2){
        cout<<1<<endl;
        for (int i = 0; i < n; i++)
        {
            if(bit[i]==2) cout<<1;
            else cout<<0;
        }

    }
    else if(z + t==n/2){
        cout<<1<<endl;
        for (int i = 0; i < n; i++)
        {
            if(bit[i]==1) cout<<1;
            else cout<<0;
        }

    }
    else cout<<-1<<endl;

    
      
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
