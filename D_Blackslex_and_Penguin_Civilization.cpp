#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    int max = (n*(n+1))/2;
    int m = pow(2,n) -1;

    int hold = m;
    set<int> s;

    
    int a = n;
    int last = hold;
    while (hold>0)
    {   
        cout<<hold<<" ";
        s.insert(hold);
        for(int i=0;i<m;i++){
            if(__popcount((hold&i))==a&&s.find(i)==s.end()){
                cout<<i<<" ";
                s.insert(i);
            }
        }
        hold/=2;
        a--;
    }

    for (int i = 0; i < m; i++)
    {
        if(s.find(i)==s.end()) cout<<i<<" ";
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
