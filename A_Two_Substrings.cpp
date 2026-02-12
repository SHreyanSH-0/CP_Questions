#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007

void solve()
{
    string a;
    cin>>a;

    int ab = 0, ba = 0 , both = 0;
    string hold;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]!='A'&&a[i]!='B'){
            if(hold=="AB") ab = 1;
            else if(hold=="BA") ba= 1;
            
            hold = "";
            continue;
        }
        
        hold.push_back(a[i]);

        if(hold=="AAA"||hold=="BBB"){
            if(hold[2]=='A') hold = "A";
            else hold = "B";
        }
        else if(hold == "AAB"){
            hold = "AB";
        }
        else if(hold == "BBA"){
            hold = "BA";
        }
        else if(hold=="ABA"){
            hold = "";
            both++;
        }
        else if(hold=="BAB"){
            hold = "";
            both++;
        }
        else if(hold=="ABB"){
            hold = "B";
            ab++;
        }
        else if(hold == "BAA"){
            hold = "A";
            ba++;
        }
        
        if(i==a.size()-1){
            if(hold=="AB") ab = 1;
            else if(hold=="BA") ba = 1;
        }
    }

    if(both + ab + ba >=2) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    
}
signed main() {

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
