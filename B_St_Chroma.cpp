#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n,x;
        cin>>n;
        cin>>x;
        for(int i=0;i<n;i++){
            if(i==x) continue;
            cout<<i<<" ";
        }
        if(x<n) cout<<x;
        cout<<endl;
    }
}