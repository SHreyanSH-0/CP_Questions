#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool check(vector<int>&v){
    int n = v.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if(s.find(v[i])!=s.end()) return false;
        s.insert(v[i]);
        while(i+1<n&&v[i]==v[i+1]) {
            i++;
        }
    }
    return true;
}

bool fun(vector<int>&v, map<int,int>&map){
    int n = v.size();
    vector<int> v2 = v, v3 = v;
    for (int i = 0; i < n; i++)
    {
        int ct = map[v[i]];
        int hold = 0;
        set<int> s;
        // cout<<i<<endl;
        for(int j=0;j<ct;j++){
            s.insert(v[i+j]);
        }
        // cout<<v[i]<<" "<<s.size()<<endl;
        if(s.size()==1){
            i+=ct-1;
        }
        else if(s.size()==2){
            int hold2 = v[i];
            for(int j=0;j<ct;j++){
                if(v[i+j]!=v[i]){
                    hold = v[i+j];
                    v[i+j] = v[i];
                    break;
                } 
            }
            // cout<<hold<<endl;
            for(int j= n-1;j>=i+ct;j--){
                if(v[j]==v[i]){
                    v[j] = hold;
                    break;
                }
            }
            
            v2[i] = hold;
            bool c = true;
            for(int j= n-1;j>=i+ct;j--){
                if(v2[j]==hold){
                    v2[j] = hold2;
                    c = false;
                    break;
                }
            }
            if(c){
                v2 = {1,2,1};
            }

            if(i-1>=0){
                int hold = v3[i-1];
                v3[i-1] = v3[i];
                for(int j= i + ct;j<n;j++){
                    if(v3[j]==v3[i-1]){
                        v3[j] = hold;
                        break;
                    }
                }
            }
            break;
        }
        else{
            return false;
        }
    }
    // for (int j = 0; j < n; j++)
    // {
    //     cout<<v[j]<<" ";
    // }cout<<endl;
    // for (int j = 0; j < n; j++)
    // {
    //     cout<<v2[j]<<" ";
    // }cout<<endl;
    // for (int j = 0; j < n; j++)
    // {
    //     cout<<v3[j]<<" ";
    // }cout<<endl;
    
    if(check(v)||check(v2)||check(v3)) return true;
    return false;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        map[v[i]]++;
    }

    vector<int> rev = v;
    reverse(rev.begin(),rev.end());

    if(fun(v,map) || fun(rev,map)) cout<<"YES"<<endl;
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
