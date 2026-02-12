#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int same = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];

            if (i > 0 && v[i] == v[i - 1])
            same++;
        }
        if(same==n-1){
            cout<<1<<endl;
        }
        else{
            
            vector<int> v2;
            v2.push_back(v[0]);
            for(int i=0;i<n;i++){
                if(v2[v2.size()-1]==v[i]){
                    continue;
                }
                else{
                    v2.push_back(v[i]);
                }
            }
            int ans = v2.size();
            for (int i = 0; i < v2.size()-1; i++)
            {
                if(v2[i]==-1)
                continue;
                if(v2[i]+1==v2[i+1]){
                    ans--;
                    v2[i+1] = -1;
                }
            }
            cout<<ans<<endl;
        }
    }
}