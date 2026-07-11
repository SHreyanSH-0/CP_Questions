#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

int score(string &hold){
    stack<char> s;
    int n = hold.size();
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        if(!s.empty()&&hold[i]==')'&&s.top()=='(') s.pop(), ans+=2;
        else s.push(hold[i]);
    }
    return ans;
    
}
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    for (int i = 0; i < n && k>0; i++)
    {
        int prev = 0;
        string hold, hold2;
        for(int j=0;j<i;j++){
            if(s[j]=='1') continue;
            else{
                hold.push_back(s[j]);
                hold2.push_back(s[j]);
            } 
        }
        hold2.push_back(s[i]);
        for(int j=i+1;j<n;j++){
            hold.push_back(s[j]);
            hold2.push_back(s[j]);
        }

        if(score(hold)<score(hold2)){
            s[i] = '1';
            k--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1') cout<<'1'<<"";
        else cout<<'0'<<"";
    }cout<<endl;
    
    

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
