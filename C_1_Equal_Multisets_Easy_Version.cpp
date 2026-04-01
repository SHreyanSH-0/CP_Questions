#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(0);

const int MOD = 1e9 + 7;

void solve() {
    // your code here
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    map<int,int> mp;
    int ct = 0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i];
        mp[b[i]]++;
        if(b[i]==-1) ct++;
    }
    // vector<pair<int,int>> p(n);
    // for(int i=0;i<n;i++){

    // }

    queue<int> q;
    
    for (int i = 0; i < n; i+=k)
    {        
        map<int,int> map1 , map2;
        for(int j=0;j<k&&i+j<n;j++){
            if(b[i+j]!=-1)
            map2[b[i+j]]++;
        }
        for(int j=0;j<k&&i+j<n;j++){
            map1[a[i+j]]++;
            if(map2.find(a[i+j])==map2.end()){
                q.push(a[i+j]);
                map2[a[i+j]]++;
            }
        } 
        if(map1!=map2) {
            cout<<"NO"<<endl;
            return;
        }
        
        for(int j = i;j<i+k&&j<n;j++){
            if(b[j]==-1){
                b[j] = q.front();
                q.pop();
            }
        }
        if(!q.empty()){
            cout<<"NO"<<endl;
            return;
        }
    }
    map<int,int> map1 , map2;
    for(int i=0;i<k;i++){
        map1[a[i]]++;
        map2[b[i]]++;
    }
    int j = 0;

    if(map1!=map2){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=k;i<n;i++,j++){
        if(a[j]!=b[j]||a[i]!=b[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}