#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    set<int> s;
    int start = 0;
    for(int i=1;i<n;i++){
        int a ,b;
        cout<<"? "<<start+1<<" "<<i+1<<endl;
        cout.flush();
        cin>>a;
        cout<<"? "<<i+1<<" "<<start+1<<endl;
        cout.flush();
        cin>>b;
        if(a>b){
            v[start] = a;
            start = i;
            s.insert(a);
        }
        else{
            v[i] = b;
            s.insert(b);
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        if(v[i]==0) v[i] = n;
    }
    cout<<"! ";
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    
    cout<<endl;
    cout.flush();

}
signed main() {

    ll test=1;
// cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
