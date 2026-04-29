#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

vector<int> fun(vector<int>&v,int &health){
    int n = v.size();
    int i  = 0;

    vector<int> ans;

    while(i<n&&v[i]>=0){
        health+=v[i];
        i++;
    }
    for(i;i<n;){
        int hold = 0;
        if(v[i]>=0){
            while(i<n&&v[i]>=0){
                hold += v[i];
                i++;
            }
        }
        else{
            while(i<n&&v[i]<0){
                hold += v[i];
                i++;
            }
        }
        if(ans.size()==0) ans.push_back(hold);
        else{
            int prev = ans[ans.size()-1];
            if(hold>=0){
                if(hold+prev>0) ans.push_back(hold);
                else {
                    if(i>=n) continue;
                    else v[i] += hold;
                }
            }
            else{
                if(prev>0){
                    ans.push_back(hold);
                }
                else ans[ans.size()-1]+=hold;
            }
        }
    }
    return ans;
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

    vector<int> left, right;
    k--;
    for(int i=k-1;i>=0;i--) left.push_back(v[i]);
    for(int i=k+1;i<n;i++) right.push_back(v[i]);
    int health = v[k];
    if(k==0||k==n-1){
        if(health>=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    left = fun(left,health);
    right = fun(right,health);
    
    int l = 0;
    int r = 0;

    while(l<left.size()&&r<right.size()){
        // cout<<l<<" "<<r<<" "<<health<<endl;
        if(left[l]>0){
            health += left[l++];
        }
        else if(right[r]>=0){
            health += right[r++];
        }
        else if(left[l]+health>=0){
            health += left[l++];
        }
        else if(right[r]+health>=0){
            health += right[r++];
        }
        else break;
    }
    if(l==left.size()||r==right.size()) cout<<"YES"<<endl;
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
