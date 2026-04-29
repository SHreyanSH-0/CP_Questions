#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool fun(vector<int>&v,int k){
    int n = v.size();
    int ct = 0;
    int idx = -1;
    for (int i = 0; i < n-2; i++)
    {
        if(v[i]<=k) ct++;
        if(ct>=(i+2)/2){
            while(i<n-3&&v[i+1]>k&&ct>=(i+3)/2){
                i++;
            } 
            idx = i;
            break;
        }
    }
    if(idx!=-1){
        int ct = 0;
        for(int i=idx+1;i<n-1;i++){
            if(v[i]<=k) ct++;
            if((ct)>=(i - idx + 1)/2) return true;
        }
        ct = 0;
        for(int i = n-1;i>idx+1;i--){
            if(v[i]<=k) ct++;
            if((ct)>=(n - i + 1)/2) return true;
        }
        return false;
    }
    else{
        int ct = 0;
        for(int i = n-1;i>=2;i--){
            if(v[i]<=k) ct++;
            if((ct)>=(n - i+1)/2){
                while(i>=2&&v[i-1]>k&&ct>=(n - i +2)/2){
                    i--;
                } 
                idx = i;
                break;
            }
        }
        if(idx!=-1){
            int ct = 0;
            for (int i = idx-1; i >=1; i--)
            {
                if(v[i]<=k) ct++;
                if((idx- i + 1)/2<=ct) return true;
            }
            
        }
        return false;
    }
    
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> rev = v;
    reverse(rev.begin(),rev.end());
    if(fun(v,k)||fun(rev,k)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main() {

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
