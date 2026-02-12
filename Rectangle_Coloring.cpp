#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
int rec(int r,int g, int b, int l
    , int w, int lc, int wc){
    if(lc+wc==4) return 0;
    int ans = 100;
    if(wc<2){
        if(r>=w) ans = min(ans, 1 + rec(r-w,g,b,l,w,lc,wc+1));
        if(g>=w) ans = min(ans, 1 + rec(r,g-w,b,l,w,lc,wc+1));
        if(b>=w) ans = min(ans, 1 + rec(r,g,b-w,l,w,lc,wc+1));
        if(r+g>=w&&r<w&&g<w) ans = min(ans, 2 + rec(r+g-w,0,b,l,w,lc,wc+1));
        if(r+b>=w&&r<w&&b<w) ans = min(ans, 2 + rec(r+b-w,g,0,l,w,lc,wc+1));
        if(g+b>=w&&b<w&&g<w) ans = min(ans, 2 + rec(r,0,b+g-w,l,w,lc,wc+1));
    }
    else{
        if(r>=l) ans = min(ans, 1 + rec(r-l,g,b,l,w,lc+1,wc));
        if(g>=l) ans = min(ans, 1 + rec(r,g-l,b,l,w,lc+1,wc));
        if(b>=l) ans = min(ans, 1 + rec(r,g,b-l,l,w,lc+1,wc));
        if(r+g>=l&&r<l&&g<l) ans = min(ans, 2 + rec(r+g-l,0,b,l,w,lc+1,wc));
        if(r+b>=l&&r<l&&b<l) ans = min(ans, 2 + rec(r+b-l,g,0,l,w,lc+1,wc));
        if(g+b>=l&&g<l&&b<l) ans = min(ans, 2 + rec(r,0,b+g-l,l,w,lc+1,wc));
        if(r+g+b>=l&&l>r&&l>b&&l>g) ans = min(ans, 3 + rec(r+g+b - l, 0,0,l,w,lc+1,wc));
    }
    return ans;
}

void solve()
{
    int l,w,r,g,b;
    cin>>l>>w>>r>>g>>b;
    int lm = max(l,w);
    int wm = min(l,w);
    cout<<rec(r,g,b,lm,wm,0,0)<<endl;
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
