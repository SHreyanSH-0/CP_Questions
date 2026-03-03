#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int s,m;
    cin>>s>>m;
    int hold = m;
    vector<int> v;
    vector<pair<int,int>> v2;
    int p = 1;
    int holds = s;
    int holdm = m;
    while(holds>0&&holdm>0){
        if(holds%2==1&&holdm%2==0){
            cout<<-1<<endl;
            return;
        }
        if(holdm%2==1) break;
        holds/=2;
        holdm/=2;
    }
    while(hold>0){
        if(hold%2==1) {
            v.push_back(p);
            v2.push_back({0,p});
        }
        p*=2;
        hold/=2;
    }
    int idx = -1;
    hold = s;
    p = 1;
    int idx2 = -1;
    while(hold>0){
        if(m%2==1) {idx++; idx2++;}
        if(hold%2==1) {
            if(v2[idx2].second==v[idx]){
                v2[idx2].first += p/v[idx];
            }
            else {
                v2[idx2].first += p/v[idx];
            }
        }
        p*=2;
        hold/=2;
        m/=2;
    }
    int low = 1, high = 1e18;
    reverse(v2.begin(),v2.end());
    
    while(low<=high){
        int mid = low + (high - low)/2;
        bool check = true;
        vector<pair<int,int>> hv = v2;
        for(int i=0;i<hv.size();i++){
            if(hv[i].first>mid){
                if(i+1<hv.size()){
                    hv[i+1].first += (__int128)abs(hv[i].first - mid)*((hv[i].second)/hv[i+1].second);
                }
                else check = false;
            }
        }
        if(check){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<low<<endl;
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
