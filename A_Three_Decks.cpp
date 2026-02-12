#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a , b , c;
        cin>>a>>b>>c;
        int x = b-a;
        a+= x;
        c -= x; 
        if(c>=a){
            if((c-a)%3==0)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
        else{
            cout<<"NO\n";
        }    
    }
}