#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    for(int l=0;l<t;l++){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> ma(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>maxi) maxi=a[i];
            ma[i]=maxi;
        }
        vector<long long> ans(n);
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            ans[n-i-1]=ma[i]+sum;
            sum+=a[i];
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}