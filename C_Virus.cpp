#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> v(m);
    vector<int> v2;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    for(int i=0;i<v.size()-1;i++){
        v2.push_back(v[i+1]-v[i]-1);
    }
    
    v2.push_back(n - v[m-1] + v[0] - 1);

    sort(v2.begin(), v2.end());

    int a = 0,ans = 0;
    for (int i = v2.size()-1; i >=0; i--)
    {
        if(v2[i]-a>1){
            ans+=v2[i]-1-a;
            a+=2;
        }
        else if(v2[i]-a==1){
            ans+=1;
        }
        a+=2;

    }
    cout << n-ans<<endl;
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
