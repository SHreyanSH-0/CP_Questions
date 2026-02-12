#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int a =1;
    int b = 2;
    vector<int> ans(n);
    int l = 0;
    int r = n-1;
    for (int i = 0; i < n; i++)
    {
        if(i%2==0){
            ans[l++] = a;
            a+=2;
        }
        else{
            ans[r--] = b;
            b+=2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
    cout<<endl;
    
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
