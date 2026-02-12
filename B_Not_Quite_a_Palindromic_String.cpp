#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;
        int zero = 0, one = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='0')
            zero++;
            else
            one++;
        }
        
        if(2*k>zero+one){
            cout<<"NO\n";
        }
        else{
            int hold = (n-2*k)/2;
            zero -=hold;
            one -=hold;
            if(zero%2==0&&one%2==0&&zero>=0&&one>=0){
                cout<<"YES\n";
            }           
            else cout<<"NO\n";
            
        }
        
    }
}