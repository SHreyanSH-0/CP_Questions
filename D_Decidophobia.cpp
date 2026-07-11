#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    
    int front = 0;
    int back = n;
    int ans = 0;
    int gift = 0;
    int nonGift = v[0];
    int ct = 2*d + 1;

    for (int i = 0; i < d; i++)
    {
        nonGift += v[++front] + v[--back];
    }

    for (int i = 0; i < n; i++)
    {
        int give =  v[i] * (2*d) - (nonGift - v[i]) - gift;
        int notGive = 0;
        // cout<<i<<" "<<give<<" "<<notGive<<endl;
        // cout<<i<<" "<<nonGift<<" "<<gift<<endl;
        if(give > notGive){
            vis[i] = true;
            ans += give;
            gift += v[i];
            nonGift -= v[i];
            ct--;
        }

        if(vis[back]){
            gift -= v[back];
        } 
        else{
            ct--;
            nonGift -= v[back];
        }


        back = (back + 1)%n;
        front = (front + 1)%n;


        if(vis[front]){
            gift += v[front];
        } 
        else{
            nonGift += v[front];
            ct++;
        } 

    }
    
    cout<<ans<<endl;
    
    
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
