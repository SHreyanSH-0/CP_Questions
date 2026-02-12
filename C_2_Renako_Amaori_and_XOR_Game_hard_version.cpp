#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        xor1 = xor1^a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
        xor2 = xor2^b[i];
    }  


    for (int i = 0; i < n; i++)
    {
        if(i%2==0){
            int newXorl = xor1^a[i]^b[i];
            int newXor2 = xor2^a[i]^b[i];

            if(newXorl>newXor2){
                xor1 = newXorl;
                xor2 = newXor2;
            }
        }
        else{
            int newXorl = xor1^a[i]^b[i];
            int newXor2 = xor2^a[i]^b[i];

            if(newXorl<newXor2){
                xor1 = newXorl;
                xor2 = newXor2;
            }
        }
    }
    
    if(xor2==xor1){
        cout<<"Tie";
    }
    else if(xor1>xor2){
        cout<<"Ajisai";
    }
    else{
        cout<<"Mai";
    }
    cout<<endl;
       
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
