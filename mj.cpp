#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int b;
    cin>>b;
    if(a<b){
        cout<<0<<endl;
    }
    else if(a==b){
        cout<<"infinity"<<endl;
    }
    else{
        int count=0;
        int n=a-b;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(i>b){
                    count++;
                }
                if(i!=n/i && n/i>b){
                    count++;
                } 
            }
        }
        cout<<count<<endl;
    }
}