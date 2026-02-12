#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string s2=s;
    sort(s2.begin(),s2.end());
    if(s2==s) cout<<"Bob"<<endl;
    else{
        int i=0,j=n-1;
        vector<int> z;
        vector<int> o;
        cout<<"Alice"<<endl;
        while(i<=j){
            if(o.size()==z.size()){
                if(s[i]=='1'){
                    o.push_back(i);
                }
                i++;
            }
            else{
                if(s[j]=='0'){
                    z.push_back(j);
                }
                j--;
            }
        }
        cout<<2*z.size()<<endl;
        for(int k=0;k<z.size();k++){
            cout<<o[k]+1<<" ";
        }
        for(int k=z.size()-1;k>=0;k--){
            cout<<z[k]+1<<" ";
        }
        cout<<endl;
    }
    
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
