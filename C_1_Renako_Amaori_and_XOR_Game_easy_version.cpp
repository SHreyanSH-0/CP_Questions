#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    int oneTotalA = 0,oneTotalB = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i]==1){
            oneTotalA++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
        if(b[i]==1){
            oneTotalB++;
        }
    }   

    int aone = 0;
    int ind1=-1 ,ind2=-1;
    int mone = 0;

    for(int i=0;i<n;i+=2){
        if((a[i]==1&&b[i]==0)||(a[i]==0&&b[i]==1)){
            aone++;
            ind1 = i;
        }
    }
    
    for(int i=1;i<n;i+=2){
        if((a[i]==1&&b[i]==0)||(a[i]==0&&b[i]==1)){
            mone++;
            ind2 = i;
        }
    }
    if(ind1>ind2){
        if(oneTotalA%2==0){
            int hold = a[ind1];
            a[ind1] = b[ind1];
            b[ind1] = hold;
        }
    }
    else if(ind2>ind1){
        if(oneTotalB%2==0){
            int hold = a[ind2];
            a[ind2] = b[ind2];
            b[ind2] = hold;
        }
    }
    int xor1 = 0,xor2 = 0;
    
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1^a[i];
    }
    for (int i = 0; i < n; i++)
    {
        xor2 = xor2^b[i];
    }

    if(xor1==xor2){
        cout<<"Tie"<<endl;
    }
    else if(xor1>xor2){
        cout<<"Ajisai"<<endl;
    }
    else cout<<"Mai"<<endl;

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
