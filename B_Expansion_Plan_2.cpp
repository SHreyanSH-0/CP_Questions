#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n,x,y;
    string s;
    cin>>n>>x>>y>>s;   

    int four = 0, eight = 0;

    for (int i = 0; i < n; i++)
    {
        if(s[i]=='4'){
            four++;
        }
        else{
            eight++;
        }
    }

    x = abs(x); 
    y = abs(y);
    
    int min8 = min(x,y);
    int min4 = max(x,y) - min8;
    for (int i = 1; i <= eight; i++)
    {
        if(eight>=i&&i<=min8&&four + eight - i >=(x+y-2*(i))){
            cout<<"YES"<<endl;
            return;
        }
    }

    if(eight>=min8&&four>=min4){
        cout<<"YES"<<endl;
    }
    else if(n>=x+y){
        cout<<"YES"<<endl;
    }
    else if(eight>=min8+min4){
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
