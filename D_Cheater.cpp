#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> p(n), g(n);
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>g[i];
    }

    int i = 0, j = 0;
    int c = 0;
    int ans = 0, ans2 = 0;
    while (c<n)
    {
        if(p[i]>g[j]){
            ans2++;
            i++;
        }
        else j++;
        c++;
    }

    int l = ceil((double)n/2);
    int m = p[0], minInd= 0;
    for (int i = 0; i < l; i++)
    {
        if(p[i]<m){
            minInd = i;
            m= p[i];
        }
    }
    int m2 = 0;
    int ind = l;
    for(int i = l; i < n; i++)
    {
        if(m2<p[i]){
            ind = i;
            m2 = p[i];
        }
    }
    if(m2>m){
        p[minInd] = m2;
        p[ind] = m;
    }

    i = 0, j = 0;
    c = 0;
    ans = 0;
    while (c<n)
    {
        if(p[i]>g[j]){
            ans++;
            i++;
        }
        else j++;
        c++;
    }
    
    cout<<max(ans,ans2)<<endl;
    
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
