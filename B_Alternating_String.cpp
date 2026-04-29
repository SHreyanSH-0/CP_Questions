#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

bool fun(string &s, string &a){
    string hold1,hold2;
    string sub1,sub2;
    int n = s.size();
    bool check = false;
    for(int i=0;i<n;i++){
        if(s[i]==a[i]||check){
            hold1.push_back(s[i]);
            hold2.push_back(s[i]);
        } 
        else{
            while(i<n&&s[i]!=a[i]){
                sub1.push_back(s[i]);

                if(s[i]=='a')
                sub2.push_back('b');
                else sub2.push_back('a');
                i++;
            }
            i--;
            reverse(sub1.begin(),sub1.end());
            reverse(sub2.begin(),sub2.end());
            hold1.append(sub1);
            hold2.append(sub2);
            check = true;
        }
    }
    // cout<<a<<" "<<hold1<<" "<<hold2<<endl;
    if(hold1==a||hold2==a) return true;
    else return false;
}

void solve()
{
    string s;
    cin>>s;
    int ct =0;
    int n = s.size();
    
    string a , b;

    for (int i = 0; i < n; i++)
    {
        if(i%2==0){
            a.push_back('a');
            b.push_back('b');
        }
        else{
            b.push_back('a');
            a.push_back('b');
        }
    }

    if(fun(s,a)||fun(s,b)) cout<<"YES"<<endl;
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
