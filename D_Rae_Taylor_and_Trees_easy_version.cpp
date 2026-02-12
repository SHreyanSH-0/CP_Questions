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

    int ct = 0;
    int m = v[0];
    
    vector<int> pending;
    int k = 0;
    for(int i=0;i<n;i++){
        if(v[i]<m){
            pending.push_back(m);
            m = v[i];
        }
        while(k<pending.size()){
            if(pending[k]<v[i]){
                k++;
            }
            else{
                break;
            }
        }
    }

    if(k==pending.size()){
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}
int main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
