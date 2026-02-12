#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int w,h,a,b,x1,y1,x2,y2;

    cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;

    if(x2>=x1&&x2<x1+a){
        if(abs(y1+b-y2)%b!=0&&abs(y1+b-y2)!=0){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    else if(x1>=x2&&x1<x2+a){
        if(abs(y1+b-y2)%b!=0&&abs(y1+b-y2)!=0){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    else if(y2>=y1&&y2<y1+b){
        if(abs(x1+a-x2)%a!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else if(y1>=y2&&y1<y2+b){
        if(abs(x1-x2+a)%a!=0&&abs(x1-x2+a)!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else{
        if(abs(x1-x2+a)%a==0||abs(y1+b-y2)%b==0)
            cout<<"YES"<<endl;
        else
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
