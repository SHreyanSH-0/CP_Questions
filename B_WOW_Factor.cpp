#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    string s;
    cin>>s;
    int w = 0, v = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='v') v++;
        else{
            if(v>0)
            w += v-1;
            v = 0;
        }
    }

    if(v>0) w+= v-1;

    int startw = 0;
    v = 0;
    long long ans = 0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='v') v++;
        else{
            if(v>0)
            startw += v-1;
            v = 0;
            
            ans += startw*(w-startw);
        }
    }
    cout<<ans<<endl;
}