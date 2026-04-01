#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void fun(string &s,map<int,vector<string>> &map){
    int n = s.size();
    stack<char> st;
    queue<char> hold;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(s[i]);
            hold.push(s[i]);
        }
        else{
            if(st.top()=='('&&s[i]==')'){
                st.pop();
                hold.push(s[i]);
            } 
            else{
                st.push(s[i]);
                hold.push(s[i]);
            }
            if(st.empty()){
                string a = "";
                int sizeee = hold.size();
                while(!hold.empty()){
                    a.push_back(hold.front());
                    hold.pop();
                }
                // cout<<s<<" "<<a<<endl;
                map[sizeee].push_back(a);
                continue;
            }
        }
    }
    
}

void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    map<int,vector<string>> map1,map2;
    
    fun(s,map1);
    fun(t,map2);

    for(auto&it:map1){
        vector<string> &v= it.second;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
    cout<<"-----------\n";
    for(auto&it:map2){
        vector<string> &v= it.second;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }

    if(map1==map2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    
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
