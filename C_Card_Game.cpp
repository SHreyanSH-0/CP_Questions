#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        int n;
        cin>>n;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            char c ;
            cin>>c;
            if(c=='A')
            a.push_back(i+1);
            else
            b.push_back(i+1);
        }
        
        if(a[0]==1&&a[a.size()-1]==n){
            cout<<"Alice\n";
        }
        else if(b[0]==1&&b[b.size()-1]==n){
            cout<<"Bob\n";
        }
        else if(a[0]==1){
            if(b.size()>1){
                cout<<"Bob\n";
            }
            else{
                cout<<"Alice\n";
            }
        }
        else{
            if(a.size()==1){
                cout<<"Bob\n";
            }
            else{
                if(a[a.size()-2]>b[b.size()-1]){
                    cout<<"Alice\n";
                }
                else{
                    cout<<"Bob\n";
                }
            }
        }
    }
}