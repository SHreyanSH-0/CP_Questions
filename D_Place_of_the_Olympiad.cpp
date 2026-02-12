#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n,k;        
        cin>>n>>m>>k;
        int ans = 1;
        int count = 1;
        if(m*n-n<k)
        cout<<m<<endl;
        else{
            int c = ceil((float)k/n);
            int a = c;
            int b = 2;
            int high = c, low = 1;
            while(high>low){
                
            }
            cout<<ans<<endl;
        }
    }
}