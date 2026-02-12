#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int z=0;z<t;z++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') ans+=cnt+1;
            else ans+=cnt-1;
        }
        cout<<ans<<endl;
    }
}