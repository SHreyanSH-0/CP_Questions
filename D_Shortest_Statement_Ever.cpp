#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
string p,q;
int rec(string&x, string&y,int i, int carry1, int carry2, int diff1, int diff2){
    int ans = LLONG_MAX;
    if(diff1==0&&diff2==0){
        // cout<<i<<carry1<<carry2<<endl;
        if(carry1==1 && i >=x.size()) return LLONG_MAX;
        if(carry2==1 && i >=y.size()) return LLONG_MAX;
        if(i>=max(x.size(),y.size())) {
            string printp = p;
            string printq = q;
            reverse(printp.begin(),printp.end());
            reverse(printq.begin(),printq.end());
            // cout<<printp<<" "<<printq<<endl;
            return 0;

        }
        int xval = i < x.size() ? x[i] - '0' : -1;
        int yval = i < y.size() ? y[i] - '0' : -1;
        int newCarry1 = 0;
        int newCarry2 = 0;
        if(carry1==1){
            if(xval == 0) {
                newCarry1 = 1;
                xval = 1;
            }
            else xval--;
        }
        if(carry2==1){
            if(yval == 0) {
                newCarry2 = 1;
                yval = 1;
            }
            else yval--;
        }

        int sub;
        int newx = xval == -1? 0 : xval;
        int newy = yval == -1? 0 : yval;
        // 00
        p.push_back('0');
        q.push_back('0');
        sub = rec(x,y,i+1,newCarry1, newCarry2,diff1,diff2);
        if(sub < LLONG_MAX/10){
            ans = min(ans, newx + newy + sub*2);
        }
        p.pop_back();
        q.pop_back();
        // 10
        if(xval!=-1){
            int fwdCarry1 = newCarry1;
            newx = xval == -1? 0 : xval;
            newy = yval == -1? 0 : yval;
            if(newx - 1 < 0){
                fwdCarry1 = 1;
                newx = xval + 2;
            }
            p.push_back('1');
            q.push_back('0');
            sub = rec(x,y,i+1,fwdCarry1, newCarry2,diff1,diff2);
            if(sub < LLONG_MAX/10){
                ans = min(ans, newx - 1 + newy + sub*2);
            } 
            p.pop_back();
            q.pop_back();
        }
        // 01
        if(yval != -1){
            int fwdCarry2 = newCarry2;
            newx = xval == -1? 0 : xval;
            newy = yval == -1? 0 : yval;
            if(newy - 1 < 0){
                fwdCarry2 = 1;
                newy = yval + 2;
            }
            p.push_back('0');
            q.push_back('1');
            sub = rec(x,y,i+1,newCarry1, fwdCarry2,diff1,diff2);
            if(sub < LLONG_MAX/10) {
                ans = min(ans, newx + newy - 1 + sub*2);
            }
            p.pop_back();
            q.pop_back();
        }
    }
    else if(diff1==1&&diff2==0){

    }
    else if(diff1==0&&diff2==1){

    }
    else{
        
    }
    return ans;
}

void solve()
{
    int x,y;
    cin>>x>>y;
    string s1,s2;
    while (x>0)
    {
        s1.push_back(x%2 + '0');
        x/=2;
    }
    while (y>0)
    {
        s2.push_back(y%2 + '0');
        y/=2;
    }
    // cout<<s1<<" "<<s2<<endl;
    cout<<rec(s1,s2,0,0,0,0,0)<<endl;
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
