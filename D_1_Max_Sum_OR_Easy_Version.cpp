#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
void solve()
{
    int l,r;
    cin>>l>>r;

    cout<<r*(r+1)<<endl;

    set<int> s;

    for (int i = 0; i <= r; i++)
    {
        s.insert(i);
    }

    int maxi = r;

    for(int i=0;i<=r;i++){
        int hold = i;
        int ans = 0;
        int p =  1;
        while(hold>=0&&ans<=maxi){
            if(hold%2==0){
                ans = (ans|p); 
            }
            hold/=2;
            p*=2;
        }
        p/=2;
        cout<<(ans^p)<<" ";
        hold = (ans^p);
        s.erase(hold);
        if(!s.empty())
        maxi = *s.rbegin();
    }    
    cout<<endl;
}
signed main() {

    ll test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
