#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long n,x;
        cin>>n>>x;
        
        if(x==0){
            if(n==1)
            cout<<-1<<endl;
            else if(n%2==0){
                cout<<n<<endl;
            }
            else{
                cout<<n+3<<endl;
            }
            
        }
        else if(x==1){
            if(n%2==0){
                cout<<n+3<<endl;
            }
            else{
                cout<<n<<endl;
            }
        }
        else{
            int a = 1,count = 0;;
            int hold = x;
            while(hold>0){
                if(hold%2==1){
                    count++;
                }
                hold/=2;
                a*=2;
            }     

            if(n-count>0){
                if((n-count)%2==0){
                    cout<<x+n-count<<endl;
                }
                else{
                    cout<<x+n-count+1<<endl;
                }
            }  
            else{
                cout<<x<<endl;
            }
        }
        
    }
}