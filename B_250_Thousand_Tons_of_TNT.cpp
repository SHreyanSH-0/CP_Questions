#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n;
        cin>>n;

        vector<int> v(n);
        long long sum = 0,ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        
        for (int i = 1; i <= n; i++)
        {
            if(n%i==0){
                long long m = 1e18;
                long long M = INT_MIN;
                for (int j = 0; j < n;)
                {
                    long long sum = 0;
                    for (int k = 0; k < i; k++,j++)
                    {
                        sum +=v[j];
                    }
                    
                    m = min(m,sum);
                    M = max(M,sum);
                }
                ans = max(ans,M-m);
            }
        }
        cout<<ans<<endl;
    }
}