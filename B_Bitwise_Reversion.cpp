#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int x,y,z;
    cin>>x>>y>>z;

    if(x==y&&y==z) {
        cout<<"YES"<<endl;
        return;
    }

    vector<int> v = {x,y,z};

    
    int a = 0, b = 0, c = 0;

    int hold = x;

    int p = 1;

    while(hold>0){
        if(hold%2==1){
            if(((a&p)==0)){
                a+=p;
            }
            if((b&p)==0){
                b+=p;
            }
        }
        p*=2;
        hold/=2;
    }
    hold = y;
    p = 1;
    while(hold>0){
        if(hold%2==1){
            if(((c&p)==0)){
                c+=p;
            }
            if((b&p)==0){
                b+=p;
            }
        }
        p*=2;
        hold/=2;
    }
    hold = z;
    p = 1;
    while(hold>0){
        if(hold%2==1){
            if(((a&p)==0)){
                a+=p;
            }
            if((c&p)==0){
                c+=p;
            }
        }
        hold/=2;
        p*=2;
    }

    if((a&b)==x&&(b&c)==y&&(c&a)==z){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
