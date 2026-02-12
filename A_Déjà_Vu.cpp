#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    string s;
    cin>>s;
    int c = 0;
    int ans = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='a') c++;
    }
    if(c==s.size()) {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        int c = true;
        for (int i = 0; i < s.size(); i++){
            if(s[i]==s[s.size()-1-i] && c && s[i]!='a'){
                cout<<'a'<<s[i]; 
                c = false;
            }
            else if(s[i]!=s[s.size()-1-i] && c){
                c =false;
                cout<<s[i]<<"a";
            }
            else{
                cout<<s[i];
            }
        }cout<<endl;
        
    }
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
