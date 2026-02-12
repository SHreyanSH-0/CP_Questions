#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    string s,t;
    cin>>n>>s>>t;
    n*=2;

    int sone = 0, tone = 0;
    bool check = true;
    for(int i=0;i<n;i++){
        if(s[i]=='1') sone++;
        if(t[i]=='1') tone++;
        if(s[i]==t[i]&&s[i]=='1'){
            if(check) {
                tone--;
                check = false;
            }
            else{
                check = true;
                sone--;
            }
        }
    }

    if((tone-sone)==1){
        cout<<"Draw";
    }
    else if(sone>tone){
        cout<<"First";
    }
    else if(tone>sone){
        cout<<"Second";
    }
    else {
        cout<<"Draw";
    }
    cout<<endl;
}
int main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
