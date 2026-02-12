#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x,y;
    string s;
    cin>>n>>x>>y>>s;

    vector<int> p(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        sum+=p[i];
    }
    
    int vala = 0, valb = 0;
    int zero = 0, one = 0;
    int amax = 0 , bmax = 0;
    int takea = 0, takeb = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0'){
            vala+=p[i];
            bmax += p[i]-1;
            if(p[i]%2==0) takea += p[i]/2 - 1;
            else takea += p[i]/2;
            zero = 1;
        } 
        else{
            valb+=p[i];
            amax+= p[i]-1;
            if(p[i]%2==0) takeb += p[i]/2 - 1;
            else takeb += p[i]/2;
            one = 1;
        }
    }


    if(vala==x&&valb==y)  {
        cout<<"YES"<<endl;
    }
    else if(vala==x){
        if(valb>y){
            cout<<"NO"<<endl;
        }
        else{
            if(one||y-valb <= bmax){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    else if(valb == y){
        if(vala>x){
            cout<<"NO"<<endl;
        }
        else{
            if(zero||(x-vala) <=amax){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    else if(vala<x&&valb<y){
        if(one&&zero) cout<<"YES"<<endl;
        else if(one){
            if( x - vala  <= amax + y- valb) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(zero){
            if(y - valb <= bmax + x - vala) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    else if(vala>x&&valb<y){
        if(vala-x<=takea && valb + vala - x <=y){
            if(y - valb <= bmax - (vala - x) ||one) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else if(vala<x&&valb>y){
        if(valb - y <= takeb&& vala + valb - y <=x){
            if(x - vala <= amax - (valb - y) || zero) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
        else cout<<"NO"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
